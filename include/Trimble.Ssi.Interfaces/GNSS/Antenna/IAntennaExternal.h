#ifndef IANTENNAEXTERNAL_H_
#define IANTENNAEXTERNAL_H_

#include "IAntenna.h"

namespace SSI
{
	/*
	* External Antenna base interface.
	*/
	class IAntennaExternal: public IAntenna
	{
	public:
		virtual ~IAntennaExternal();

		/*
		* Sets the Antenna ID.
		*
		* @param id The ID.
		*/
		virtual void setID(int id) = 0;

		/*
		* Sets the Antenna serial number.
		*
		* @param serialNumber
		*            The serial number.
		*/
		virtual void setSerialNumber(std::string serialNumber) = 0;
	};
}
#endif