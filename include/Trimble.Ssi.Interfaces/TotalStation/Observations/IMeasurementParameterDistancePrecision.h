#ifndef IMEASUREMENTPARAMETERDISTANCEPRECISION_H_
#define IMEASUREMENTPARAMETERDISTANCEPRECISION_H_

#include "IMeasurementParameter.h"

namespace SSI
{
	/**
	* Defines a measurement parameter for distance precision settings.
	* Only supported from SSeries instruments.
	* The measurement will be performed until the defined precision is achieved.
	* Note this parameter depends on:
	* - the instrument
	* - the EDM Mode
	* - the distance
	* - the atmospheric conditions
	* - the stability of the target
	*
	* ### Timeouts ###
	* The following table shows the timeouts for S Series measurements.
	* Target | Timeout
	* -------|--------
	* Prism | 30 secs
	* DR | 120 secs
	*
	* ### Accuracy ###
	* The following table shows the maximum accuracy of S Series measurements.
	* Instrument | Prism | Direct Reflex
	* -----------|-------|--------------
	* %Trimble S3 | 2 mm + 2 ppm | 3 mm + 2 ppm
	* %Trimble S6 DR Plus | 2 mm + 2 ppm |  2 mm + 2 ppm
	* %Trimble S8 DR Plus | 2 mm + 2 ppm | 2 mm + 2 ppm
	* %Trimble S8 DR HP | 1 mm + 1 ppm | 3 mm + 2 ppm
	* %Trimble VX | 2 mm + 2 ppm | 2 mm + 2 ppm
	*For detailed information see the appropriate device manual.
	*/
	class IMeasurementParameterDistancePrecision : public IMeasurementParameter
	{
	public:
		virtual ~IMeasurementParameterDistancePrecision();

		/**
		*set the standard deviation.
		*@param standardDeviation the standard deviation
		*/
		virtual void setStandardDeviation(double standardDeviation) = 0;

		/**
		*get the standard deviation.
		*@return the standard deviation
		*/
		virtual double getStandardDeviation() const = 0;

		/**
		* get the minimum standard deviation.
		* @return the standard deviation
		*/
		virtual double getStandardDeviationMinLimit() const = 0;
	
		/**
		* get the maximum standard deviation.
		* @return the standard deviation
		*/
		virtual double getStandardDeviationMaxLimit() const = 0;
	};
}
#endif