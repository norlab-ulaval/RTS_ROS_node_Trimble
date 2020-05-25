#ifndef FOCUSTYPE_H_
#define FOCUSTYPE_H_

namespace SSI
{
	/**
	* Represents the type of a focus.
	*/
	enum FocusType
	{
		FT_Automatic,	/**< Represents a type of a focus handled automatically */
		FT_Distance		/**< Represents a type of a focus determined by a slope distance */
	};
}
#endif