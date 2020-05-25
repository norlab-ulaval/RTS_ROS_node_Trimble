#ifndef TRIMBLE360CHECKIDMODE_H_
#define TRIMBLE360CHECKIDMODE_H_

namespace SSI
{
	/** Represents the mode which describes when the defined ID gets checked against the ID of the %Trimble 360 targets.
	* To get an enumeration of supported <see cref="Trimble360CheckIdMode"/> values, use <see cref="ITrimble360Target.ListSupportedCheckIdModes"/>.
	* Use <see cref="ITrimble360Target.CheckIdMode"/> to get or set the check id mode of the Trimble360 target.
	* @see ISsiTargets
	*/
	enum Trimble360CheckIdMode
	{
		TCID_Search,			/**< The target id will only be checked during the search process. */
		TCID_SearchAndMeasure,	/**< The target id will be checked during the search and measure process. */
		TCID_Always				/**< The target id will be checked all the time. */
	};
}
#endif