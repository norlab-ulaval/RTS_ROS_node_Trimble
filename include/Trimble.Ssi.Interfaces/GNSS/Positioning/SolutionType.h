#ifndef SOLUTIONTYPE_H_
#define SOLUTIONTYPE_H_

namespace SSI
{
	/**
	* Represents solution type of <see cref="ISolutionTypeObservation"/>.
	* The value of <see cref="ISolutionTypeObservation.SolutionType"/> will be one of these values.
	* <seealso cref="ISolutionTypeObservation"/>
	* <seealso cref="ISsiPositioning"/>
	*/
	enum SolutionType
	{
		ST_Autonomous=1,	/**< Solution type is autonomous. */
		ST_SBAS=2,			/*SBAS satellite solution*/
		ST_Differential=3,	/**< Solution type is differential. */
		ST_RTKFloat,		/**< Solution type is RTK float. */
		ST_RTKFixed,		/**< Solution type is RTK fixed. */
		ST_XFill=9,			/**< Solution is XFill. */
		ST_RTX=10,			/**< Solution is RTX. */
        ST_XFillRTX=11, 	/**< HDSolutionType is XFillRTX. */
		ST_RTXCode=12,  	/**< Solution is RTXCode. */
	};
	/*Dev: Hardcoded enum Modification should be removed later.*/
}
#endif
