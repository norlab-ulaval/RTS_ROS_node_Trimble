#ifndef ICAMERAFEATUREFOCUS_H_
#define ICAMERAFEATUREFOCUS_H_

#include "ICameraFeature.h"
#include "Focus/IFocusStateChangedListener.h"
#include "Focus/FocusState.h"

namespace SSI
{
	/**
	* This <see cref="ICameraFeature"/> is availiable if the Camera is capable of focusing.
	*/
	class ICameraFeatureFocus : public ICameraFeature
	{
	public:
		virtual ~ICameraFeatureFocus();
	
		/**
		* register a listener for listening.
		* @param IVideoStreamingUpdateListener to listen
		*/
		virtual void addFocusStateChangedListener(IFocusStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IVideoStreamingUpdateListener to listen
		*/
		virtual void removeFocusStateChangedListener(IFocusStateChangedListener& listener) = 0;

		/**
		* Gets the current focus state.
		* @return The current focus state.
		*/
		virtual FocusState getCurrentFocusState() const = 0;

		/**
		* Determines whether this instance can focus to a defined environment around a pixel.
		* @return <c>true</c> if this instance can focus to pixel; otherwise, <c>false</c>.
		*/
		virtual bool canFocusToPixel() const = 0;

		/**
		* Focuses to a defined environment around a pixel.
		* @param normalizedColumn The normalized column.
		* @param normalizedRow The normalized row.
		* @param normalizedRadius The normalized radius.
		*/
		virtual void focusToPixel(double normalizedColumn, double normalizedRow, double normalizedRadius) = 0;

		/**
		* Focuses to a defined distance.
		* @param distance The distance.
		*/
		virtual void focusToDistance(double distance) = 0;
	};
}
#endif