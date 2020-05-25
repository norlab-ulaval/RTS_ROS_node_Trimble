#ifndef SALLY_CALLBACKS_H
#define SALLY_CALLBACKS_H
#include "SensorProperties/ISensorProperty.h"
#include "SensorProperties/SensorPropertyType.h"
#include "Power/IPowerSource.h"
#include "Power/ICurrentPowerSourceChangedListener.h"

#include "IdleAngles/IIdleAnglesChangedListener.h"
#include "Observations/ITrackingObservationsListener.h"
#include "Observations/ITrackingStateChangedListener.h"
#include "Observations/TSObservationContainer.h"
#include "Tilt/ITiltChangedListener.h"
#include "Tilt/ITiltStateChangedListener.h"

#include "Calibration/ICalibrationProgressListener.h"
#include "Calibration/ICalibrationStateChangedListener.h"

#include "Video/IVideoStreamingUpdateListener.h"
#include "IStreamingStateChangedListener.h"

class SsiCallbacks : public SSI::IIdleAnglesChangedListener,
    public SSI::ITrackingObservationsListener,
    public SSI::ITrackingStateChangedListener,
    public SSI::ICurrentPowerSourceChangedListener,
    public SSI::IVideoStreamingUpdateListener,
    public SSI::IStreamingStateChangedListener,
    public SSI::ITiltChangedListener,
    public SSI::ITiltStateChangedListener
{
public:
    SsiCallbacks();
    virtual ~SsiCallbacks();

    void OnSensorProperty(SSI::ISensorProperty& prop, SSI::SensorPropertyType type);
    void OnPower(SSI::IPowerSource& source);
    void OnMeasure(SSI::TSObservationContainer& container);
    void OnIdleAngles(const SSI::SphericalAngles& angles);
	void OnImage(SSI::IImageCapture& image);

    /*ICurrentPowerSourceChangedListener*/
    virtual void onCurrentPowerSourceChanged(const SSI::PowerSourceEvent& powerSourceEvent);

    /*IIdleAnglesChangedListener*/
    virtual void onIdleAnglesChanged(const SSI::IdleAnglesChangedEvent& idleAnglesChangedEvent);
    
    /*ITrackingObservationsListener*/
    virtual void observationTracked(const SSI::TrackingObservationsEvent& event);

    /*ITrackingStateChangedListener*/
    virtual void trackingStateChanged(const SSI::TrackingStateChangedEvent& event);

    /*IStreamingStateChangedListener*/
    virtual void streamingStateChanged(const SSI::StreamingStateChangedEvent& event);

    /*IVideoStreamingUpdateListener*/
    virtual void videoStreamigUpdate(const SSI::VideoStreamingUpdateEvent& event);

    /*ITiltChangedListener*/
    virtual void tiltChanged(const SSI::TiltChangedEvent& tiltChangedEvent);

    /*ITiltStateChangedListener*/
    virtual void tiltStateChanged(const SSI::TiltStateChangedEvent& tiltStateChangedEvent);

private:
};

#endif