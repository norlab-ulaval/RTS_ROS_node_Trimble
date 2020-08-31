#include "radio_message_serialize.h"

size_t double_to_bytes(std::vector<byte> &byte_buffer, double input_val){
    size_t bytes_copied = sizeof(double);
    byte* local_buffer = new byte[bytes_copied];

    memcpy((void*) local_buffer, (const void*) &input_val, bytes_copied);

    for(int i = 0; i < bytes_copied; i++){
        byte_buffer.push_back(local_buffer[i]);
    }

    delete local_buffer;
    return bytes_copied;
}

double bytes_to_double(std::vector<byte> &byte_buffer, size_t start_index){
    size_t bytes_copied = sizeof(double);
    double retval;

    if(start_index+bytes_copied > byte_buffer.size())
        throw std::range_error("Not enough bytes in the byte_buffer to assemble a double.");

    byte* local_buffer = new byte[bytes_copied];

    for(int i = 0; i < bytes_copied; i++){
        local_buffer[i] = byte_buffer[i+start_index];
    }

    memcpy((void*) &retval, (const void*) local_buffer, bytes_copied);

    delete local_buffer;
    return retval;

}


size_t uint_to_bytes(std::vector<byte> &byte_buffer, uint32_t input_val){
    size_t bytes_copied = sizeof(uint32_t);
    byte* local_buffer = new byte[bytes_copied];

    memcpy((void*) local_buffer, (const void*) &input_val, bytes_copied);

    for(int i = 0; i < bytes_copied; i++){
        byte_buffer.push_back(local_buffer[i]);
    }

    delete local_buffer;
    return bytes_copied;
}

uint32_t bytes_to_uint(std::vector<byte> &byte_buffer, size_t start_index){
    size_t bytes_copied = sizeof(uint32_t);
    uint32_t retval;

    if(start_index+bytes_copied > byte_buffer.size())
        throw std::range_error("Not enough bytes in the byte_buffer to assemble a uint32_t.");

    byte* local_buffer = new byte[bytes_copied];

    for(int i = 0; i < bytes_copied; i++){
        local_buffer[i] = byte_buffer[i+start_index];
    }

    memcpy((void*) &retval, (const void*) local_buffer, bytes_copied);

    delete local_buffer;
    return retval;
}



void pack_theodolite_message_to_bytes(std::vector<byte> &byte_buffer,
                                      byte theodolite_number,
                                      byte status,
                                      double elevation,
                                      double azimuth,
                                      double distance,
                                      uint32_t secs,
                                      uint32_t nsecs){
    byte_buffer.clear();
    byte_buffer.push_back(theodolite_number);
    byte_buffer.push_back(status);
    double_to_bytes(byte_buffer, elevation);
    double_to_bytes(byte_buffer, azimuth);
    double_to_bytes(byte_buffer, distance);
    uint_to_bytes(byte_buffer, secs);
    uint_to_bytes(byte_buffer, nsecs);
}


bool unpack_theodolite_message_from_bytes(std::vector<byte> &byte_buffer,
                                          byte &theodolite_number,
                                          byte &status,
                                          double &elevation,
                                          double &azimuth,
                                          double &distance,
                                          uint32_t &secs,
                                          uint32_t &nsecs){

    size_t expected_size = 2*sizeof(byte) + 3*sizeof(double) + 2*sizeof(uint32_t);
    if(byte_buffer.size() != expected_size)
        return false;

    size_t start_index = 0;

    theodolite_number = byte_buffer[start_index];
    start_index += sizeof(byte);

    status = byte_buffer[start_index];
    start_index += sizeof(byte);

    elevation = bytes_to_double(byte_buffer, start_index);
    start_index += sizeof(double);

    azimuth = bytes_to_double(byte_buffer, start_index);
    start_index += sizeof(double);

    distance = bytes_to_double(byte_buffer, start_index);
    start_index += sizeof(double);

    secs = bytes_to_uint(byte_buffer, start_index);
    start_index += sizeof(uint32_t);

    nsecs = bytes_to_uint(byte_buffer, start_index);
    start_index += sizeof(uint32_t);

    return true;
}

void pack_theodolite_time_to_bytes(std::vector<byte> &byte_buffer,
                                   byte command_code,
                                   uint32_t secs,
                                   uint32_t nsecs)
{
    byte_buffer.clear();
    byte_buffer.push_back(command_code);
    uint_to_bytes(byte_buffer, secs);
    uint_to_bytes(byte_buffer, nsecs);
}


bool unpack_theodolite_time_from_bytes(std::vector<byte> &byte_buffer,
                                       byte &command_code,
                                       uint32_t &secs,
                                       uint32_t &nsecs)
{
    size_t expected_size = sizeof(byte) + 2*sizeof(uint32_t);
    if(byte_buffer.size() != expected_size)
        return false;

    size_t start_index = 0;

    command_code = byte_buffer[start_index];
    start_index += sizeof(byte);

    secs = bytes_to_uint(byte_buffer, start_index);
    start_index += sizeof(uint32_t);

    nsecs = bytes_to_uint(byte_buffer, start_index);
    start_index += sizeof(uint32_t);

    return true;
}

