#ifndef IPOSITIONSIGMAOBSERVATION_H_
#define IPOSITIONSIGMAOBSERVATION_H_

#include "IGNSSObservation.h"

namespace SSI
{
	/**
	* Represents a Position Sigma information observation.
	*/
	class IPositionSigmaObservation: public IGNSSObservation
	{
	public:
		virtual ~IPositionSigmaObservation();

		/* Gets the SigmaNorth.
		* @return The North 1 sigma error.
		*/
		virtual double getSigmaNorth()= 0;

		/* Gets the SigmaEast.
		* @return The East 1 sigma error.
		*/
		virtual double getSigmaEast()= 0;

		/* Gets the SigmaHeight.
		* @return The Height 1 sigma error.
		*/
		virtual double getSigmaHeight()= 0;

		/* Gets the CovarianceNE.
		* @return The Covariance east-north (dimensionless).
		*/
		virtual double getCovarianceNE()= 0;

		/* Gets the SemiMajorAxis.
		* @return The error ellipse semi-major axis 1 sigma error
		*/
		virtual double getSemiMajorAxis()= 0;

		/* Gets the SemiMinorAxis.
		* @return The error ellipse semi-minor axis 1 sigma error
		*/
		virtual double getSemiMinorAxis()= 0;

		/* Gets the Orientation.
		* @return The error ellipse orientation
		*/
		virtual double getOrientation()= 0;
	};
}
#endif