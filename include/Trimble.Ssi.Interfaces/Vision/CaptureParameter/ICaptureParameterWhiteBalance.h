#ifndef ICAPTUREPARAMETERWHITEBALANCE_H_
#define ICAPTUREPARAMETERWHITEBALANCE_H_

#include "Image/WhiteBalanceType.h"
#include <vector>
#include "IGeneralCaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter for setting a pre configured white balance preset.
	*/
	class ICaptureParameterWhiteBalance : public IGeneralCaptureParameter
	{
	public:
		virtual ~ICaptureParameterWhiteBalance();

		/**
		* Lists the supported white balance types.
		* @return the supported white balance types
		*/
		virtual std::vector<WhiteBalanceType> listSupportedWhiteBalanceTypes() const = 0;

		/**
		* Determines whether the specified white balance type is supported.
		* @param whiteBalanceType Type of the white balance.
		* @return true if supported; otherwise false
		*/
		virtual bool isSupported(WhiteBalanceType whiteBalanceType) const = 0;

		/**
		* Gets the type of the white balance.
		* @return The type of the white balance.
		*/
		virtual WhiteBalanceType getWhiteBalanceType() const = 0;
	
		/**
		* Sets the type of the white balance.
		* @param whiteBalanceType The type of the white balance.
		*/
		virtual void setWhiteBalanceType(WhiteBalanceType whiteBalanceType) = 0;
	};
}
#endif