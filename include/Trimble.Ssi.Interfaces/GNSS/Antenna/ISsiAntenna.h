#ifndef ISSIANTENNA_H_
#define ISSIANTENNA_H_

#include "ISsiInterface.h"
#include "IAntenna.h"
#include "IAntennaExternal.h"
#include "IAntennaInternal.h"
#include <vector>

namespace SSI
{
	/*
	* Provides members to access the Antenna of the GNSS Receiver.
	*
	* @remarks
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiAntenna : public ISsiInterface
	{
	public:
		virtual ~ISsiAntenna();

		/* 
		* Lists the supported antenna types.
		*
		* @returns An enumeration of all supported Antenna types.
		* @remarks Please be aware, that the underlying enumeration later may contain values, which are not known now.
		*/
		virtual std::vector<AntennaType> listSupportedAntennaTypes() const = 0;

		/*
		* Determines whether the specified type is supported.
		*
		* @param type The type.
		* @return boolean.
		*/
		virtual bool isSupported(AntennaType type) const = 0;

		/*
		* Gets the antenna.
		*
		* @param type The type.
		* @return Antenna object.
		* @exception cref="NotConnectedException">This sensor instance is not connected.
		* @exception cref="ArgumentException">Invalid type argument.
		*/
		virtual IAntenna& getAntenna(AntennaType type) const = 0;

		/*
		* Sets the antenna.
		*
		* @param antenna The antenna.
		* @exception cref="NotConnectedException">This sensor instance is not connected. 
		* @exception cref="ArgumentNullException">antenna argument is null.
		*/
		virtual void setAntenna(IAntennaExternal& antenna) = 0;
	};
}
#endif
