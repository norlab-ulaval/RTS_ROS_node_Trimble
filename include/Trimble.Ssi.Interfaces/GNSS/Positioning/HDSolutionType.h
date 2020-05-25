#ifndef HDSOLUTIONTYPE_H_
#define HDSOLUTIONTYPE_H_

namespace SSI
{
	/**
	* Represents HD solution type of <see cref="IHDSolutionTypeObservation"/>.
	* The value of <see cref="IHDSolutionTypeObservation.HDSolutionType"/> will be one of these values.
	* <seealso cref="IHDSolutionTypeObservation"/>
	* <seealso cref="ISsiPositioning"/>
	*/
	enum HDSolutionType
	{
		HDST_Autonomous=1,		/**< HDSolutionType is autonomous. */
		HDST_SBAS=2,			/*SBAS satellite solution*/
		HDST_Differential=3,	/**< HDSolutionType is differential. */
		HDST_HDRTK=6,			/**< HDSolutionType is HDRTK. */
		HDST_XFill=9,			/**< HDSolutionType is XFill. */
		HDST_RTX=10,			/**< HDSolutionType is RTX. */
        HDST_XFillRTX=11,		/**< HDSolutionType is XFillRTX. */
		HDST_RTXCode=12,		/**< HDSolutionType is RTXCode. */
	};
	/*Dev: Hardcoded enum Modification should be removed later.*/
}
#endif