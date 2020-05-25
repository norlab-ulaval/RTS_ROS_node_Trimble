#ifndef POWERSOURCETYPE_H_
#define POWERSOURCETYPE_H_

namespace SSI
{
	/*
	*  possible power source types.
	*/
	enum PowerSourceType
	{
		PST_InternalBattery,	/**< internal battery */
		PST_RadioBattery,		/**< radio battery */
		PST_ExternalPower		/**< external power */
	};
}
#endif
