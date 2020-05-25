#ifndef REFERENCESYSTEM_H_
#define REFERENCESYSTEM_H_

namespace SSI
{
	/**
	* The coordinate reference system.
	*/
	enum ReferenceSystem
	{
		RS_WGS84,	/**< The WGS84 Coordinate system. */
		RS_ITRF2008 /**< The ITRF2008 Coordinate system. */
	};
}
#endif