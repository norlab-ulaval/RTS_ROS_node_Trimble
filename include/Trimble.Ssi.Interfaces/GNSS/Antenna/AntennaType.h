#ifndef ANTENNATYPE_H_
#define ANTENNATYPE_H_

namespace SSI
{
	/*
	* Represents antenna type.
	*
	* @remarks To get an enumeration of supported <see cref="AntennaType"/> values, use <see cref="ISsiAntenna.ListSupportedAntennaTypes"/>.
	* @remarks Use <see cref="ISsiAntenna.GetAntenna"/> to get an <see cref="IAntenna"/>, which can be used to access the antenna of the GNSS Receiver
	* <seealso cref="ISsiAntenna"/>
	*/
	enum AntennaType
	{
		/*
		* Antenna is internal.
		*/
		Internal,

		/*
		* Antenna is external.
		*/
		External
	};
}
#endif