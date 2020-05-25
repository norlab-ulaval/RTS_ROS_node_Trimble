#ifndef ISSIDISPLAYBETA_H_
#define ISSIDISPLAYBETA_H_

#include "ISsiInterface.h"
#include "IDisplayElement.h"
#include "DisplayElementType.h"
#include "IButtonListener.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to change the second face display of the instrument and to react on button events
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	* @see ISsiTargets
	*/
	class ISsiDisplayBeta : public ISsiInterface
	{
	public:
		virtual ~ISsiDisplayBeta();

		/**
		* Gets the default button listener for the instrument.
		*/
		virtual IButtonListener& getDefaultButtonListener() = 0;

		/**
		* Sets the button listener.
		* @param IButtonListener the listener
		*/
		virtual void setButtonListener(IButtonListener& listener) = 0;

		/**
		* Lists the supported element types.
		* @return An enumeration of supported Element types.
		*/
		virtual std::vector<DisplayElementType> listSupportedElementTypes() = 0;

		/**
		* Determines whether the specified element type is supported.
		* @param the display element type
		* @return true if specified type is supported, otherwise false.
		*/
		virtual bool isSupported(DisplayElementType type) = 0;

		/**
		* Creates the display element.
		* @param the display element type
		* @return An IDisplayElement of the requested type.
		*/
		virtual IDisplayElement* createDisplayElement(DisplayElementType type) = 0;

		/**
		* Updates the display.
		* @param An enumeration of supported Element types to be display.
		*/
		virtual void updateDisplay(std::vector<IDisplayElement*>& displayElements) = 0;

		/**
		* Clear the display
		*/
		virtual void clearDisplay() = 0;

		/**
		* Gets an indication if the display is illuminated or not.
		* @return true if display is illuminated, otherwise false
		*/
		virtual bool getIllumination() = 0;

		/**
		* Sets the illumination.
		* @param If set to true the display gets illuminated
		*/
		virtual void setIllumination(bool on) = 0;
	};
}
#endif