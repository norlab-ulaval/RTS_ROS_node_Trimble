#ifndef IRADICONFIGURATIONFORWARDERRORCORRECTION
#define IRADICONFIGURATIONFORWARDERRORCORRECTION

#include <vector>
#include "IRadioConfigurationGnss.h"

namespace SSI
{
	/**
	* The radio parameter for changing the forward error correction option.
	*/
	class IRadioConfigurationForwardErrorCorrection : public virtual IRadioConfigurationGnss
	{
	public:
		virtual ~IRadioConfigurationForwardErrorCorrection();

		/**
		* Gets the forward error correction.
		* @return forward error correction
		*/
		virtual bool getErrorCorrectionOn() const = 0;
	
		/**
		* Sets the forward error correction.
		* @param forward error correction
		*/
		virtual void setErrorCorrectionOn(bool errorCorrection) = 0;
	};
}
#endif