#ifndef EXPOSURETYPE_H_
#define EXPOSURETYPE_H_

namespace SSI
{
	/**
	* Represents the type of exposure settings.
	*/
	enum ExposureType
	{
		ET_Automatic,	/**< The exposure gets regulated automatically */
		ET_Manual		/**< The exposure gets regulated manually */
	};
}
#endif