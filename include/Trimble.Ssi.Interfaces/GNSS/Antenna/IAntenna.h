#ifndef IANTENNA_H_
#define IANTENNA_H_

#include "AntennaType.h"
#include <string>

namespace SSI
{
	/*
	* Base interface for accessing antenna types.
	*
	* @remarks Use <see cref="ISsiAntenna.GetAntenna"/> to get an <see cref="IAntenna"/> by it's type.
	* <seealso cref="ISsiAntenna"/>
	*/
	class IAntenna
	{
	public:
		virtual ~IAntenna();

		/*
		* Gets the type.
		* @return AntennaType
		*/
		virtual AntennaType getType() const = 0;

		/*
		* Gets the Antenna ID.
		*
		* @return The ID.
		*/
		virtual int getID() const = 0;

		/*
		* Gets the Antenna serial number.
		*
		* @return The serial number.
		*/
		virtual std::string getSerialNumber() = 0;
	};
}
#endif