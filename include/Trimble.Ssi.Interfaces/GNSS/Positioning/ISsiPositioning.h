#ifndef ISSIPOSITIONING_H_
#define ISSIPOSITIONING_H_

#include "ISsiInterface.h"
#include "IPositionListener.h"
#include "PositioningParameterType.h"
#include "IPositioningParameter.h"
#include "PositioningSettings.h"
#include "IStreamingStateChangedListener.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access positioning data from the GNSS Receiver.
	*/
	class ISsiPositioning: public ISsiInterface {
	public:
		virtual ~ISsiPositioning();

		/**
		* register a listener for listening.
		* @param IPositionListener to listen
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
		virtual const std::vector<PositioningParameterType> listSupportedPositioningParameterTypes()=0;

		/**
		* Determines whether the specified type is supported.
		* @return bool
		*/
		virtual bool isSupported(PositioningParameterType type)=0;

		/*
		* Creates the positioning parameter.
		* @return IPositioningParameter&
		*/
		virtual IPositioningParameter* createPositioningParameter(PositioningParameterType positioningParameterType)=0;

		/**
		* Starts the positioning.
		* @param PositioningSettings
		*/
		virtual void startPositioning(PositioningSettings& settings)=0;

		/**
		* Stops the positioning.
		*/
		virtual void stopPositioning()=0;
	};
}
#endif