#ifndef DISPLAYELEMENTTYPE_H_
#define DISPLAYELEMENTTYPE_H_

namespace SSI
{
	/**
	* Represents the type of a display element
	* To get an enumeration of supported DisplayElementType values, use ISsiDisplayBeta.listSupportedElementTypes
	* Use ISsiDisplayBeta.createDisplayElement to create a specific display element on the DisplayElementType
	* @see ISsiDisplayBeta
	*/
	enum DisplayElementType
	{
		DET_Text,		/** Type of a display element which is defined by text. */
		DET_Bitmap		/** Type of a search parameter which is defined by bitmap. */
	};
}
#endif