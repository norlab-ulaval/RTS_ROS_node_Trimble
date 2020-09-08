#ifndef SALLY_INSTRUMENT_H
#define SALLY_INSTRUMENT_H

#include "IDriverManager.h"
#include "DriverManagerInstance.h"
#include "IDriverInformation.h"
#include "VideoStreamingListener.h"
#include "Observations/ITrackingObservationsListener.h"

class SsiInstrument
{
public:
    SsiInstrument(void);
    virtual ~SsiInstrument(void);

    static SsiInstrument& GetInstrument();

    int LoadDriver(const char* sDriver = "SSeries");
    int FreeDriver();
    int Connect(const char* sType = "usb", const char* sPort = "0");
    int DisConnect();
    int GetProperty();
    int Power(int option);

    enum TargetMode
    {
        MODE_PRISM = 0,
        MODE_AUTOLOCK,
        MODE_DR,
        MODE_DR_LASER,
        MODE_DR_WEAK,
        MODE_MULTITRACK
    };

    //Ts
    int ChangeFace();
    int DoMeasure(bool bAngleonly);
    int Tracking(bool bStart, int param = 0);
    int Tracking(bool bStart, SSI::ITrackingObservationsListener* listener, int param = 0);
    int IdleAngles(int option);
    int Target(int mode, int target_id = 1);
    int Video(bool bStart, VideoStreamingListener& video_streaming_listener);
    int Video(bool bStart);
    int Image();
    int Elevel(bool bStart);
    int TrackLigth();
    int setServosAnglesSynchronous(double HA, double VA);
    std::string PrintDriverInformation();

private:
    SSI::IDriverManager& _DriverManager;
    SSI::IDriver* _pDriver;
    SSI::ISensor* _pSensor;

    class SsiCallbacks* _pCallback;
};

#endif
