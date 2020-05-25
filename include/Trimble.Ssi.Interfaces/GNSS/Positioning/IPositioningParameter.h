#ifndef IPOSITIONINGPARAMETER_H_
#define IPOSITIONINGPARAMETER_H_

#include "PositioningParameterType.h"

namespace SSI
{
	/*
	* Represents positioning parameter.
	*/
	class IPositioningParameter
	{
	public:
		virtual ~IPositioningParameter();
	
		/*
		* Gets the type.
		* @return PositioningParameterType
		*/
		virtual PositioningParameterType getType()=0;

		/**
		* Clone
		* @return reference of an object allocated in heap
		*/
		//virtual IPositioningParameter* clone() const=0;
	};
}
#endif