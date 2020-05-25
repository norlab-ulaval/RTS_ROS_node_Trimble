#ifndef ILINKPARAMETER_H_
#define ILINKPARAMETER_H_

#include "LinkParameterType.h"

namespace SSI
{
	/*
	* Represents Link parameter.
	*/
	class ILinkParameter
	{
	public:
		virtual ~ILinkParameter();
	
		/*
		* Gets the type.
		* @return LinkParameterType
		*/
		virtual LinkParameterType getType() const=0;

		//virtual ILinkParameter* clone() const=0;
	};
}
#endif