#ifndef ISSIELECTRONICBUBBLE_H
#define ISSIELECTRONICBUBBLE_H

#include "IElectronicBubbleStateListener.h"
#include "ITiltValuesListener.h"
#include "ElectronicBubbleState.h"
#include "TiltValues.h"
#include "ISsiInterface.h"
#include "CalibrationAgeInformation.h"
#include "IStreamingStateChangedListener.h"
#include "TiltRate.h"

namespace SSI
{
	/**
	* Provides members to access electronic bubble of the GNSS Receiver.
	* <remarks>
	* For a brief description of features and usage of various @see ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces).
	* </remarks>
	*/
	class ISsiElectronicBubble: public ISsiInterface
	{
	public:
		virtual ~ISsiElectronicBubble();

		/**
		* register a listener for listening.
		* @param IElectronicBubbleStateListener to listen
		*/
		virtual void addElectronicBubbleStateListener(IElectronicBubbleStateListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IElectronicBubbleStateListener to listen
		*/
		virtual void removeElectronicBubbleStateListener(IElectronicBubbleStateListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param ITiltValuesListener to listen
		*/
		virtual void addTiltValuesListener(ITiltValuesListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param ITiltValuesListener to listen
		*/
		virtual void removeTiltValuesListener(ITiltValuesListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param ITiltValuesListener to listen
		*/
		virtual void addStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param ITiltValuesListener to listen
		*/
		virtual void removeStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* gets the current streaming state.
		*/
		virtual StreamingState getStreamingState() const = 0;

		/**
		* Gets the state of the electronic bubble.
		* @return The state of the calibration.
		*/
		virtual ElectronicBubbleState getElectronicBubbleState() = 0;

		/**
		* Gets the tilt values.
		* @return Tilt Values.
		*/
		virtual TiltValues getTiltValues() = 0;

		/**
		* Starts the streaming tilt values.
		*/
		virtual void startStreamingTiltValues() = 0;

        /**
		* Starts the streaming tilt values.
        * @param tiltRate Tilt update rate.
		*/
        virtual void startStreamingTiltValues(TiltRate tiltRate) = 0;

		/**
		* Stops the streaming tilt values.
		*/
		virtual void stopStreamingTiltValues() = 0;

		/**
		* Gets the Calibration age.
		* @return Calibration age.
		*/
		virtual CalibrationAgeInformation getCalibrationAgeInformation() = 0;

		/**
		* Sets the calibration age.
		* @param calibrationAgeLimit The calibration limit in hours.
		*/
		virtual void setCalibrationAgeLimit(int calibrationAgeLimit) = 0;
	};
}
#endif