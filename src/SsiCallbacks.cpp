#include "SsiCallbacks.h"

#include "SensorProperties/ISensorSerialNumberProperty.h"
#include "SensorProperties/ISensorFirmwareProperty.h"
#include "SensorProperties/ISensorNameProperty.h"
#include "SensorProperties/ISensorModelProperty.h"
#include "Power/IExternalPower.h"
#include "Power/IInternalBattery.h"
#include "Power/IRadioBattery.h"
#include "Observations/IAngleObservation.h"
#include "Observations/IDistanceObservation.h"
#include "Observations/ITimeObservation.h"

#include <iostream>

extern int ssi_output(const char* fmt, ...);

SsiCallbacks::SsiCallbacks()
{
    
}

SsiCallbacks::~SsiCallbacks()
{
}

void SsiCallbacks::OnSensorProperty(SSI::ISensorProperty& prop, SSI::SensorPropertyType type)
{
    switch(type)
    {
    case SSI::SPT_Firmware:
        {
            SSI::ISensorFirmwareProperty& fw = (SSI::ISensorFirmwareProperty&)prop;
            ssi_output("Firmware: %s\n", fw.getValue().c_str());
        }
        break;
    case SSI::SPT_SerialNumber:
        {
            SSI::ISensorSerialNumberProperty& sn = (SSI::ISensorSerialNumberProperty&)prop;
            ssi_output("SerialNumber: %s\n", sn.getValue().c_str());
        }
        break;
    case SSI::SPT_Model:
        {
            SSI::ISensorModelProperty& mo = (SSI::ISensorModelProperty&)prop;
            ssi_output("Model: %s\n", mo.getValue().c_str());
        }
        break;
    case SSI::SPT_Name:
        {
            SSI::ISensorNameProperty& na = (SSI::ISensorNameProperty&)prop;
            ssi_output("Name: %s\n", na.getValue().c_str());
        }
        break;
	default:
		break;
    }
}

const char* GetExternalPowerState(SSI::ExternalPowerState state)
{
    switch(state)
    {
    case SSI::EPS_Ok:
        return "OK";
    case SSI::EPS_Critical:
        return "Critical";
	default:
		break;
    }
    return "Unknown";
}

const char* GetPowerState(SSI::BatteryState state)
{
    switch(state)
    {
    case SSI::BS_Ok:
        return "OK";
    case SSI::BS_Low:
        return "Low";
    case SSI::BS_Critical:
        return "Critical";
	default:
		break;
    }
    return "Unknown";
}

void SsiCallbacks::OnPower(SSI::IPowerSource& source)
{
    SSI::PowerSourceType type = source.getPowerSourceType();
    switch(type)
    {
    case SSI::PST_ExternalPower:
        {
            SSI::IExternalPower& ep = (SSI::IExternalPower&)source;
            ssi_output("ExternalPower: %s\n", GetExternalPowerState(ep.getExternalPowerState()));
        }
        break;
    case SSI::PST_InternalBattery:
        {
            SSI::IInternalBattery& ip = (SSI::IInternalBattery&)source;
            ssi_output("InternalBattery: %s ", GetPowerState(ip.getBatteryState()));
            ssi_output("Level %d\n", (ip.getBatteryState() == SSI::BS_Unknown) ? -1 : ip.getLevel());
        }
        break;
    case SSI::PST_RadioBattery:
        {
            SSI::IRadioBattery& rp = (SSI::IRadioBattery&)source;
            ssi_output("RadioBattery: %s ", GetPowerState(rp.getBatteryState()));
            ssi_output("Level %d\n", (rp.getBatteryState() == SSI::BS_Unknown) ? -1 : rp.getLevel());
        }
        break;
    }
}

void SsiCallbacks::OnMeasure(SSI::TSObservationContainer& container)
{
    SSI::IAngleObservation* angle = 0;
    SSI::IDistanceObservation* distance = 0;
	SSI::ITimeObservation* time = 0;
    std::vector<SSI::ITSObservation*> obs = container.getObservations();
    for(std::vector<SSI::ITSObservation*>::iterator it = obs.begin(); it != obs.end(); it++)
    {
        if((*it)->getObservationType() == SSI::OT_AngleObservation)
        {
            angle = (SSI::IAngleObservation*)(*it);
        }
        else if((*it)->getObservationType() == SSI::OT_DistanceObservation)
        {
            distance = (SSI::IDistanceObservation*)(*it);
        }
		else if ((*it)->getObservationType() == SSI::OT_TimeObservation)
		{
			time = (SSI::ITimeObservation*)(*it);
		}
    }

    if(angle){
        ssi_output("Measure: Ha %.6f Va %.6f Sd %.4f Tm %.3f\n", 
        angle->getAngles().getHorizontalAngle(), angle->getAngles().getVerticalAngle(),
        distance ? distance->getSlopeDistance():0, time ? time->getTimeUtc():0);
        
        std::cout << "Measure: Ha " << angle->getAngles().getHorizontalAngle() << " Va " << angle->getAngles().getVerticalAngle() <<
                  " Sd " << (distance ? distance->getSlopeDistance():0) << " Tm " << (time ? time->getTimeUtc():0) << std::endl;
    } 
}

void SsiCallbacks::OnIdleAngles(const SSI::SphericalAngles& angles)
{
    ssi_output("IdleAngle: Ha %.6f Va%.6f\n", angles.getHorizontalAngle(), angles.getVerticalAngle());
}

void SsiCallbacks::OnImage(SSI::IImageCapture& image)
{
	ssi_output("Get image format %d width %d height %d\n", image.getFormat(), image.getWidth(), image.getHeight());
}

void SsiCallbacks::onCurrentPowerSourceChanged(const SSI::PowerSourceEvent& powerSourceEvent)
{
    SSI::IPowerSource& source = powerSourceEvent.getPowerSource();
    OnPower(source);
}

void SsiCallbacks::onIdleAnglesChanged(const SSI::IdleAnglesChangedEvent& idleAnglesChangedEvent)
{
    const SSI::SphericalAngles& angles = idleAnglesChangedEvent.getAngles();
    OnIdleAngles(angles);
}

void SsiCallbacks::observationTracked(const SSI::TrackingObservationsEvent& event)
{
    SSI::IAngleObservation* angle = 0;
    SSI::IDistanceObservation* distance = 0;
	SSI::ITimeObservation* time = 0;

    try
    {
        SSI::TSObservationContainer container = event.getObservationContainer();

        std::vector<SSI::ITSObservation*> obs = container.getObservations();
        for(std::vector<SSI::ITSObservation*>::iterator it = obs.begin(); it != obs.end(); it++)
        {
            if((*it)->getObservationType() == SSI::OT_AngleObservation)
            {
                angle = (SSI::IAngleObservation*)(*it);
            }
            else if((*it)->getObservationType() == SSI::OT_DistanceObservation)
            {
                distance = (SSI::IDistanceObservation*)(*it);
            }
			else if ((*it)->getObservationType() == SSI::OT_TimeObservation)
			{
				time = (SSI::ITimeObservation*)(*it);
			}
        }

        if(angle)
            ssi_output("Tracking: Ha %.6f Va %.6f Sd %.4f Tm %.3f\n",
            angle->getAngles().getHorizontalAngle(), angle->getAngles().getVerticalAngle(),
            distance ? distance->getSlopeDistance() : 0, time ? time->getTimeUtc() : 0);

    }
    catch(SSI::InvalidTrackingObservationsException&e )
    {
        const char* reason ="Unknown";
        if(e.isTiltOutOfRange())
        {
            reason = "TiltOutOfRange";
        }
        else if (e.isWrongTargetDistance())
        {
            reason = "WrongTargetDistance";
        }

        ssi_output("Tracking: %s due to %s\n", e.what(), reason);
    }
}

void SsiCallbacks::trackingStateChanged(const SSI::TrackingStateChangedEvent& event)
{
    SSI::TrackingState state = event.getTrackingState();
    const char* s = "Unknown";
    switch(state)
    {
    case SSI::OTS_NotTracking:
        s = "OTS_NotTracking";
        break;
    case SSI::OTS_Starting:
        s = "OTS_Starting";
        break;
    case SSI::OTS_Stopping:
        s = "OTS_Stopping";
        break;
    case SSI::OTS_Tracking:
        s = "OTS_Tracking";
        break;
    }
    
    ssi_output("TrackingState %s\n", s);
}

void SsiCallbacks::streamingStateChanged(const SSI::StreamingStateChangedEvent& event)
{
    //enum StreamingState
    //{
    //    SS_Starting, /**< Streaming state is Starting. */
    //    SS_Streaming, /**< Streaming state is Starting. */
    //    SS_Stopping, /**< Streaming state is Stopping. */
    //    SS_NotStreaming /**< Streaming state is NotStreaming. */
    //};
    SSI::StreamingState state = event.getStreamingState();

    const char* sState = "Unknown";

    switch(state)
    {
    case SSI::SS_Starting:
        sState = "SS_Starting";
        break;
    case SSI::SS_Streaming:
        sState = "SS_Streaming";
        break;
    case SSI::SS_Stopping:
        sState = "SS_Stopping";
        break;
    case SSI::SS_NotStreaming:
        sState = "SS_NotStreaming";
        break;
    default:
        break;
    }

    ssi_output("Video stream status %s\n", sState);
}

void SsiCallbacks::videoStreamigUpdate(const SSI::VideoStreamingUpdateEvent& event)
{
    const SSI::IImageCapture& image = event.getImageCapture();
    ssi_output("Video stream get frame format %d width %d height %d\n", image.getFormat(), image.getWidth(), image.getHeight());
}

void SsiCallbacks::tiltChanged(const SSI::TiltChangedEvent& tiltChangedEvent)
{
    SSI::LevelTilt tilt = tiltChangedEvent.getTilt();
    SSI::TiltState status = tilt.getTiltState();

    const char* sState = "TS_Unknown";

    switch(status)
    {
    case SSI::TS_Ok:
        sState = "TS_Ok";
        break;
    case SSI::TS_OutOfRange:
        sState = "TS_OutOfRange";
        break;
    case SSI::TS_NeedsCalibration:
        sState = "TS_NeedsCalibration";
        break;
    default:
        break;
    }

    ssi_output("eLevelTilt Sighting %.6f Trunnion %.6f Status %s\n",tilt.getSighting(), tilt.getTrunnion(), sState);
}

void SsiCallbacks::tiltStateChanged(const SSI::TiltStateChangedEvent& tiltStateChangedEvent)
{
    SSI::TiltState status = tiltStateChangedEvent.getTiltState();
    const char* sState = "TS_Unknown";

    switch(status)
    {
    case SSI::TS_Ok:
        sState = "TS_Ok";
        break;
    case SSI::TS_OutOfRange:
        sState = "TS_OutOfRange";
        break;
    case SSI::TS_NeedsCalibration:
        sState = "TS_NeedsCalibration";
        break;
    default:
        break;
    }
    ssi_output("eLevelTilt Status Changed to %s\n", sState);
}
