#ifndef GNSSOBSERVATIONTYPE_H_
#define GNSSOBSERVATIONTYPE_H_

namespace SSI
{

	/*
	* Defines constant Observation type objects.
	*/
	enum GNSSObservationType
	{
		/*
		* The coordinate.
		*/
		OT_Coordinate,

		/*
		* The solution type.
		*/
		OT_SolutionType,

		/*
		*The HD solution type.
		*/
		OT_HDSolutionType,

		/*
		*The RMS.
		*/
		OT_RMS,

		/*
		* The precision.
		*/
		OT_Precision,

		/*
		* The satellites.
		*/
		OT_Satellites,

		/*
		* The dilution of precision
		*/
		OT_DilutionOfPrecision,

		/*
		* The epoch.
		*/
		OT_Epoch,

		/*
		*The GPS time.
		*/
		OT_GPSTime,

		/*
		*The correction age.
		*/
		OT_CorrectionAge,

		/*
		* The RTK status
		*/
		OT_RTKStatus,

		/*
		* The reference system
		*/
		OT_ReferenceSystem,		

		/*
		*The extended dilution of precision.
		*/
		OT_ExtendedDilutionOfPrecision,

		/*
		*The tilt observation.
		*/
		OT_GNSSTilt,

		/*
		* The ground coordinate observation
		*/
		OT_GroundCoordinate,

		/*
		* The ground precision
		*/
		OT_GroundPrecision,

		/*
		* The tilt precision
		*/
		OT_TiltPrecision,

		/*
		* The tilt debug observation
		*/
		OT_MagneticDisturbance,

		/*
		* The velocity data
		*/
		OT_Velocity,

		/*
		* The VCV observation
		*/
		OT_VCV,

		/*
		* The Ratio at initialization
		*/
		OT_RatioAtInitialization,

		/*
		* The position sigma observation
		*/
		OT_PositionSigma,

		/*
		* The rtx position type observation
		*/
		OT_RTXPositionType,

		/*
		* The rtx velocity observation
		*/
		OT_RTXVelocity,

        /*
         * The geoid undulation
         */
        OT_GeoidUndulation,
		
        /*
         * The IMU alignment status
         */
        OT_IMUAlignmentStatus
		
	};
}
#endif