#ifndef ISSIIDLEANGLES_H_
#define ISSIIDLEANGLES_H_

#include "ISsiInterface.h"
#include "../Common/SphericalAngles.h"
#include "IIdleAnglesChangedListener.h"
#include "IStreamingStateChangedListener.h"

namespace SSI
{
	/**
	* Support for streaming the idle angles of an instrument.
	*/
	class ISsiIdleAngles : public ISsiInterface
	{
	public:
		virtual ~ISsiIdleAngles();

		/**
		* register a listener for listening.
		* @param IIdleAnglesChangedListener to listen
		*/
		virtual void addIdleAnglesChangedListener(IIdleAnglesChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IIdleAnglesChangedListener to listen
		*/
		virtual void removeIdleAnglesChangedListener(IIdleAnglesChangedListener& listener) = 0;	

		/**
		* register a listener for listening.
		* @param IStreamingStateChangedListener to listen
		*/
		virtual void addStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IIdleAnglesChangedListener to listen
		*/
		virtual void removeStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* gets the current streaming state
		*/
		virtual StreamingState getStreamingState() const = 0;

		/**
		* get the idle angles.
		* @return the idle angles
		*/
		virtual SphericalAngles getIdleAngles() const = 0;

		/**
		* start the streaming of idle angles.
		*/
		virtual void startStreamingIdleAngles() = 0;

		/**
		* stop the streaming of idle angles.
		*/
		virtual void stopStreamingIdleAngles() = 0;
	};
}
#endif