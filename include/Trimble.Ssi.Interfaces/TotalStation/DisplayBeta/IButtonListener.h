#ifndef IBUTTONLISTENER_H_
#define IBUTTONLISTENER_H_

#include "ButtonType.h"

namespace SSI
{
	/**
	* listens for button events.
	*/
	class IButtonListener
	{
	public:
		virtual ~IButtonListener();

		/**
		* the button event down fired.
		* @param type the button type
		*/
		virtual void onButtonDown(const ButtonType type) = 0;

		/**
		* the button event long pressed fired.
		* @param type the button type
		*/
		virtual void onButtonLongPressed(const ButtonType type) = 0;

		/**
		* the button event up fired.
		* @param type the button type
		*/
		virtual void onButtonUp(const ButtonType type) = 0;
	};
}
#endif