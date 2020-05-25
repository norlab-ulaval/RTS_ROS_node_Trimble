#ifndef WHITEBALANCETYPE_H_
#define WHITEBALANCETYPE_H_

namespace SSI
{
	/**
	* Represents white balancing presets
	*/
	enum WhiteBalanceType
	{
		WBT_Automatic,		/**< Represents automatic white balance application */
		WBT_Daylight,		/**< Represents white balancing under daylight conditions */
		WBT_LightBulb,		/**< Represents white balancing under light bulb conditions */
		WBT_Neon,			/**< Represents white balancing under neon light conditions */
		WBT_Cloudy,			/**< Represents white balancing under cloudy conditions */
		WBT_AutomaticSimple /**< Represents automatic simple white balance application */
	};
}
#endif