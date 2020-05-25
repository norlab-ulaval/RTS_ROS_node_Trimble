#ifndef ISSITILTEDMEASUREMENT_H_
#define ISSITILTEDMEASUREMENT_H_

#include "TiltSensorCalibrationState.h"
#include "IPositionListener.h"
#include "ISsiInterface.h"
#include "IStreamingStateChangedListener.h"
#include "PositioningParameterType.h"
#include "IPositioningParameter.h"
#include "PositioningSettings.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access positioning data from the GNSS Receiver.
	*/
	class ISsiTiltedMeasurement : public ISsiInterface
	{
	public:
		virtual ~ISsiTiltedMeasurement();

		/**
		* Gets the state of the tilt sensor calibration.
		* @return the state of the tilt sensor calibration.
		*/
		virtual TiltSensorCalibrationState getTiltSensorCalibrationState()=0;

		/**
		* register a listener for listening.
		* @param IPositionListener to listens
		*/
		virtual void addPositionListener(IPositionListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IPositionListener to listen
		*/
		virtual void removePositionListener(IPositionListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param IStreamingStateChangedListener to listen
		*/
		virtual void addStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IPositionListener to listen
		*/
		virtual void removeStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* get StreamingState.
		* @return StreamingState
		*/
		virtual StreamingState getStreamingState() const = 0;

        /**
        * Lists the supported positioning parameter types.
        * @return std::vector<PositioningParameterType>
        */
        virtual const std::vector<PositioningParameterType> listSupportedPositioningParameterTypes() = 0;

        /**
        * Determines whether the specified type is supported.
        * @return bool
        */
        virtual bool isSupported(PositioningParameterType type) = 0;

        /*
        * Creates the positioning parameter.
        * @return IPositioningParameter&
        */
        virtual IPositioningParameter* createPositioningParameter(PositioningParameterType positioningParameterType) = 0;

		/**
		* Starts the positioning.
		* @param settings PositioningSettings.
		*/
		virtual void startPositioning(PositioningSettings& settings)=0;

		/**
		* Stops the positioning.
		*/
		virtual void stopPositioning()=0;
	};
}
#endif