#ifndef IRADIOCONFIGURATIONTRANSPARENTFST_H_
#define IRADIOCONFIGURATIONTRANSPARENTFST_H_

#include "IRadioConfigurationPacificCrest.h"

namespace SSI
{
	/**
	* Represents a Transparent configuration.
	*/
	class IRadioConfigurationTransparentFST : public virtual IRadioConfigurationPacificCrest
	{
	public:
		virtual ~IRadioConfigurationTransparentFST();

	};
}
#endif