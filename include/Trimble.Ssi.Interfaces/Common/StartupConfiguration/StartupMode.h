#ifndef STARTUPMODE_H_
#define STARTUPMODE_H_

namespace SSI
{
	/**
	* Represents the mode of the startup.
	* To get an enumeration of supported <see cref="StartupMode"/> values, use <see cref="ISsiStartupConfiguration.ListSupportedStartupModes"/>.
	*/
	enum StartupMode
	{
		SM_Survey,		/**< Survey startup configuration. If connected via Radio Base, the connection will get lost.*/
		SM_Monitoring,	/**< Monitoring startup configuration. If connected via Radio Single, the connection will get lost.*/
		SM_AutoLevel,   /**<  Automatic task startup leveling.*/
		SM_AutoStart,	/**<  Automatic task startup configuration.*/
        SM_GNSSOnly,    /**<  GNSS-only mode configuration. for GNSS*/
        SM_INS          /**<  INS mode configuration. for GNSS*/
	};
}
#endif