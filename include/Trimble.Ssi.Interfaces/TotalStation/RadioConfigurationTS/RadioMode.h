#ifndef RADIOMODE_H_
#define RADIOMODE_H_

namespace SSI
{
	/**
	* Represents the mode of the radio.
	* To get an enumeration of supported <see cref="RadioMode"/> values, use <see cref="ISsiRadioConfigurationTS.listSupportedRadioModes"/>.
	*/
	enum RadioMode
	{
		RM_Single,	/**< Used for radio configurations for instruments in survey mode */
		RM_Base,	/**< Used for radio configurations for instruments in monitoring mode */
	};
}
#endif
