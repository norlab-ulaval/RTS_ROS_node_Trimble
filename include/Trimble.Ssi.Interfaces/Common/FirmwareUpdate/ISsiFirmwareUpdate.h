#ifndef ISSIFIRMWAREUPDATE_H_
#define ISSIFIRMWAREUPDATE_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides members to access the firmare update of an instrument.
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiFirmwareUpdate : public ISsiInterface
	{
	public:
		virtual ~ISsiFirmwareUpdate();

		/**
		* enables FTP in the instrument.
		*/
		virtual void initialize(const char* firmwareFile) = 0;

		/**
		* updates the Firmware of the instrument.
		* @param Firmware file name.
		*/
		virtual void firmwareUpdate() = 0;
	};
}
#endif