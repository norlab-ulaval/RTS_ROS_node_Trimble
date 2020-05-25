#ifndef IRADIOCONFIGURATIONSCRAMBLER_H_
#define IRADIOCONFIGURATIONSCRAMBLER_H_

#include <vector>
#include "IRadioConfigurationGnss.h"

namespace SSI
{
	/**
	*  The radio parameter for describing the scrambler spacing
	*/
	class IRadioConfigurationScrambler : public virtual IRadioConfigurationGnss
	{
	public:
		virtual ~IRadioConfigurationScrambler();

		/**
		* get the scrambler option
		* @return the scrambler
		*/
		virtual bool getScramblerOn() const = 0;

		/**
		* sets the scrambler option.
		*/
		virtual void setScramblerOn(bool scrambler) = 0;
	};
}
#endif