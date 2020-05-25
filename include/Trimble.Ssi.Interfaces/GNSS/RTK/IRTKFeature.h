#ifndef IRTKFEATURE_H_
#define IRTKFEATURE_H_

#include "RTKFeatureType.h"

namespace SSI
{
	/*
	* Represents an optional RTK Feature
	*/
	class IRTKFeature
	{
	public:
		virtual ~IRTKFeature();
	
		/*
		* Gets the type of the RTK Feature.
		* @return RTK Feature Type
		*/
		virtual RTKFeatureType getType()=0;
	};
}
#endif