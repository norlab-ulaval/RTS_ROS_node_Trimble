#ifndef RTKFEATURETYPE_H_
#define RTKFEATURETYPE_H_

namespace SSI
{
	/*
	* Represents optional features, which can be applied to an RTK session.
	*/
	enum RTKFeatureType
	{
		/*
		* Represents the XFill feature.
		*/
		RTKFeatureType_XFill,
	
		/*
		* Represents the SBAS feature.
		*/
		RTKFeatureType_SBAS,
	};
}
#endif