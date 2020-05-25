#ifndef IIMAGEPROPERTYWHITEBALANCE_H_
#define IIMAGEPROPERTYWHITEBALANCE_H_

#include "IImagingProperty.h"
#include "../Image/WhiteBalanceType.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the applied white balancing preset
	*/
	class IImagePropertyWhiteBalance : public IImagingProperty
	{
	public:
		virtual ~IImagePropertyWhiteBalance();
	
		/**
		* Gets the type of the white balance.
		* @return The type of the white balance.
		*/
		virtual WhiteBalanceType getWhiteBalanceType() const = 0;
	};
}
#endif