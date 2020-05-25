#ifndef ISSIAUTHENTIICATION_H_
#define ISSIAUTHENTIICATION_H_

#include "ISsiInterface.h"
#include <string>

namespace SSI
{
	/**
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiAuthentication : public ISsiInterface
	{
	public:
		virtual ~ISsiAuthentication();

		/**
		* Changes the current instrument PIN.
		* PIN is valid between 0000 and 9999
		* Set PIN to 0000 means turn PIN authentication off
		* @param pin PIN used to protect the instrument.
		*/
        virtual void setAuthenticationPin(const std::string& pin) = 0;

		/**
		* Gets the current PIN of the instrument.
		* @return Returns the current instrument PIN.
		*/
		virtual std::string getAuthenticationPin() const = 0;

		/**
		* Gets the PUK of the instrument.
		* @return Returns the instrument PUK to unlock a PUK locked instrument.
		*/
		virtual std::string getAuthenticationPuk() const = 0;
	};
}
#endif