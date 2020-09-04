#include "lora_radio.h"


static const int CHANNEL = 0;
byte message[INPUT_LORA_BUFFER_SIZE];
bool sx1272 = true;
byte receivedbytes;

/*******************************************************************************
 *
 * Configure these values!
 *
 *******************************************************************************/

// SX1272 - Raspberry connections
int ssPin = 6;
int dio0  = 7;
int RST   = 0;

// Set spreading factor (SF7 - SF12)
sf_t sf = SF9;

// Set center frequency
uint32_t  freq = 905000000; // in Mhz! (868.1)

void print_byte(byte input, const char* text){
	printf("The byte %s contains: %X, which is:\n7 6 5 4 3 2 1 0 \n", text, input);
        for(int i = 7; i >= 0; i--){
       		if(input & (0x01 << i))
		{
			printf("1 ");
		}else
		{
			printf("0 ");
		}
        }
	printf("\n");
}

void die(const char *s)
{
    perror(s);
    exit(1);
}

void selectreceiver()
{
    digitalWrite(ssPin, LOW);
}

void unselectreceiver()
{
    digitalWrite(ssPin, HIGH);
}

byte readReg(byte addr)
{
    unsigned char spibuf[2];

    selectreceiver();
    spibuf[0] = addr & 0x7F;
    spibuf[1] = 0x00;
    wiringPiSPIDataRW(CHANNEL, spibuf, 2);
    unselectreceiver();

    return spibuf[1];
}

void writeReg(byte addr, byte value)
{
    unsigned char spibuf[2];

    spibuf[0] = addr | 0x80;
    spibuf[1] = value;
    selectreceiver();
    wiringPiSPIDataRW(CHANNEL, spibuf, 2);

    unselectreceiver();
}

static void opmode (uint8_t mode) {
    writeReg(REG_OPMODE, (readReg(REG_OPMODE) & ~OPMODE_MASK) | mode);
}

static void opmodeLora() {
    uint8_t u = OPMODE_LORA;
    if (sx1272 == false)
        u |= 0x8;   // TBD: sx1276 high freq
    writeReg(REG_OPMODE, u);
}


void SetupLoRa()
{
    
    digitalWrite(RST, HIGH);
    delay(100);
    digitalWrite(RST, LOW);
    delay(100);

    byte version = readReg(REG_VERSION);

    if (version == 0x22) {
        // sx1272
        printf("SX1272 detected, starting.\n");
        sx1272 = true;
    } else {
        // sx1276?
        digitalWrite(RST, LOW);
        delay(100);
        digitalWrite(RST, HIGH);
        delay(100);
        version = readReg(REG_VERSION);
        if (version == 0x12) {
            // sx1276
            printf("SX1276 detected, starting.\n");
            sx1272 = false;
        } else {
            printf("Unrecognized transceiver.\n");
            //printf("Version: 0x%x\n",version);
            exit(1);
        }
    }

    opmode(OPMODE_SLEEP);
    opmodeLora();

    // set frequency
    uint64_t frf = ((uint64_t)freq << 19) / 32000000;
    writeReg(REG_FRF_MSB, (uint8_t)(frf>>16) );
    writeReg(REG_FRF_MID, (uint8_t)(frf>> 8) );
    writeReg(REG_FRF_LSB, (uint8_t)(frf>> 0) );

    writeReg(REG_SYNC_WORD, 0x34); // LoRaWAN public sync word

    if (sx1272) {
        if (sf == SF11 || sf == SF12) {
            writeReg(REG_MODEM_CONFIG,0x0B);
        } else {
            writeReg(REG_MODEM_CONFIG,0x0A);
        }
        writeReg(REG_MODEM_CONFIG2,(sf<<4) | 0x04);
    } else {
        if (sf == SF11 || sf == SF12) {
            writeReg(REG_MODEM_CONFIG3,0x0C);
        } else {
            writeReg(REG_MODEM_CONFIG3,0x04);
        }
        writeReg(REG_MODEM_CONFIG,0x84);    //was 0x72 for 125kHz and error code 4/5, 0x88 is for 250kHz and 4/8 code
        writeReg(REG_MODEM_CONFIG2,(sf<<4) | 0x04);
    }

    if (sf == SF10 || sf == SF11 || sf == SF12) {
        writeReg(REG_SYMB_TIMEOUT_LSB,0x05);
    } else {
        writeReg(REG_SYMB_TIMEOUT_LSB,0x08);
    }
    writeReg(REG_MAX_PAYLOAD_LENGTH,0xff );
    writeReg(REG_PAYLOAD_LENGTH,PAYLOAD_LENGTH);
    writeReg(REG_HOP_PERIOD,0x00);
    writeReg(REG_FIFO_ADDR_PTR, readReg(REG_FIFO_RX_BASE_AD));

    writeReg(REG_LNA, LNA_MAX_GAIN);

}

boolean receive() {

    
    byte irqflags = readReg(REG_IRQ_FLAGS);
    
    // clear rxDone
    writeReg(REG_IRQ_FLAGS, 0x40);
   
    // This part is to see if the sender added a CRC
    /*byte reg_hop_chanel = readReg(REG_HOP_CHANNEL);

    if((reg_hop_chanel & 0x40))
    {
        printf("CRC requested\n");
    }
    else
    {
        printf("CRC NOT requested\n");
    }
    */

    //  payload crc: 0x20
    if((irqflags & 0x20) == 0x20)
    {
        //printf("CRC error\n");
        writeReg(REG_IRQ_FLAGS, 0x20);
        return false;
    } else {

        byte currentAddr = readReg(REG_FIFO_RX_CURRENT_ADDR);
        byte receivedCount = readReg(REG_RX_NB_BYTES);
        receivedbytes = receivedCount;

	if((int)receivedbytes > INPUT_LORA_BUFFER_SIZE) throw std::overflow_error("Received LORA data larger than available buffer");

        writeReg(REG_FIFO_ADDR_PTR, currentAddr);

        for(int i = 0; i < receivedCount; i++)
        {
            message[i] = (char)readReg(REG_FIFO);
        }
    
    }
    return true;
}

bool receivepacket(std::vector<byte>& data_out, bool& crc_ok, bool show_data) {

    long int SNR;
    int rssicorr;

    if(digitalRead(dio0) == 1)
    {
        if(receive()) {
            if(show_data){
                byte value = readReg(REG_PKT_SNR_VALUE);
                if( value & 0x80 ) // The SNR sign bit is 1
                {
                   // Invert and divide by 4
                   value = ( ( ~value + 1 ) & 0xFF ) >> 2;
                   SNR = -value;
                }
                else
                {
                   // Divide by 4
                   SNR = ( value & 0xFF ) >> 2;
                }
            
                if (sx1272) {
                    rssicorr = 139;
                } else {
                   rssicorr = 157;
                }  

                printf("Packet RSSI: %d, ", readReg(0x1A)-rssicorr);
                printf("RSSI: %d, ", readReg(0x1B)-rssicorr);
                printf("SNR: %li, ", SNR);
                printf("Length: %i", (int)receivedbytes);
                printf("\n");
                printf("Payload first two chars: %.*s\n", (((int)receivedbytes)>=2) ? 2 : ((int)receivedbytes), message);
                printf("Payload: ");
        		for(int i = 0; i < (int)receivedbytes; i++){
                    printf("%X|", message[i]);                    
                }
                printf("\n");	
	    
            }
            
            // pass the data to the vector
            data_out.clear();
            for(int i = 0; i < (int)receivedbytes; i++){
            	data_out.push_back(message[i]);
            }

	    crc_ok = true;
	    return true;
        } // received a message
        else{  // the CRC was bad
	    crc_ok = false;
            return true;	
        }

    } // dio0=1
    return false;
}

static void configPower (int8_t pw) {
    if (sx1272 == false) {
        // no boost used for now
        if(pw >= 17) {
            pw = 15;
        } else if(pw < 2) {
            pw = 2;
        }
        // check board type for BOOST pin
        writeReg(RegPaConfig, (uint8_t)(0x80|(pw&0xf)));
        writeReg(RegPaDac, readReg(RegPaDac)|0x07);
        
        // increase the current limit to 200 mA
        writeReg(RegOcp, 0x3B);

    } else {
        // set PA config (2-17 dBm using PA_BOOST)
        if(pw > 17) {
            pw = 17;
        } else if(pw < 2) {
            pw = 2;
        }
        writeReg(RegPaConfig, (uint8_t)(0x80|(pw-2)));
    }
}


static void writeBuf(byte addr, byte *value, byte len) {                                                       
    unsigned char spibuf[256];                                                                          
    spibuf[0] = addr | 0x80;                                                                            
    for (int i = 0; i < len; i++) {                                                                         
        spibuf[i + 1] = value[i];                                                                       
    }                                                                                                   
    selectreceiver();                                                                                   
    wiringPiSPIDataRW(CHANNEL, spibuf, len + 1);                                                        
    unselectreceiver();                                                                                 
}

bool txlora(byte *frame, byte datalen, int timeout) {
 
    int sending_time_counter = 0;

    // set the IRQ mapping DIO0=TxDone DIO1=NOP DIO2=NOP
    writeReg(RegDioMapping1, MAP_DIO0_LORA_TXDONE|MAP_DIO1_LORA_NOP|MAP_DIO2_LORA_NOP);
    // clear all radio IRQ flags
    writeReg(REG_IRQ_FLAGS, 0xFF);
    
    // mask all IRQs but TxDone
    //writeReg(REG_IRQ_FLAGS_MASK, ~IRQ_LORA_TXDONE_MASK);

    // initialize the payload size and address pointers
    writeReg(REG_FIFO_TX_BASE_AD, 0x00);
    writeReg(REG_FIFO_ADDR_PTR, 0x00);
    writeReg(REG_PAYLOAD_LENGTH, datalen);

    // download buffer to the radio FIFO
    writeBuf(REG_FIFO, frame, datalen);
    // now we actually start the transmission

    opmode(OPMODE_TX);

    while(!(digitalRead(dio0) == 1) && sending_time_counter < timeout)
    {
        delay(1);
        sending_time_counter ++;
    }
    
    if(digitalRead(dio0) == 1) return true;
    else return false;
}

bool txlora(std::string & data, int timeout){
    bool ret_val;
    unsigned char *send_message = new unsigned char[data.length()+1];
    strcpy((char *)send_message, data.c_str());

    ret_val = txlora(send_message, strlen((char *)send_message), timeout);
    delete send_message;
    return ret_val;
}


bool txlora(std::vector<byte>& data_in, int timeout){
    bool ret_val;
    size_t num_of_bytes = data_in.size();
    unsigned char *send_message = new unsigned char[num_of_bytes];
    
    for(int i = 0; i < num_of_bytes; i++){
        send_message[i] = data_in[i];    
    }

    ret_val = txlora(send_message, num_of_bytes, timeout);
    delete send_message;
    return ret_val;
}



void General_setup_lora()
{
    wiringPiSetup () ;
    pinMode(ssPin, OUTPUT);
    pinMode(dio0, INPUT);
    pinMode(RST, OUTPUT);

    wiringPiSPISetup(CHANNEL, 500000);

    SetupLoRa();

    opmode(OPMODE_STANDBY);
	
    writeReg(RegPaRamp, (readReg(RegPaRamp) & 0xF0) | 0x08); // set PA ramp-up time 50 uSec
    configPower(20);
}

void Config_rx_mode()
{
    // clear the irq
    writeReg(REG_IRQ_FLAGS, 0xFF);
    // set the IRQ mapping DIO0=RxDone DIO1=NOP DIO2=NOP
    writeReg(RegDioMapping1, MAP_DIO0_LORA_TXDONE | MAP_DIO1_LORA_NOP | MAP_DIO2_LORA_NOP);
    opmode(OPMODE_RX);
}

void Config_tx_mode()
{
    opmode(OPMODE_STANDBY);
}

    
    
   
    
	

   


    

   	   
