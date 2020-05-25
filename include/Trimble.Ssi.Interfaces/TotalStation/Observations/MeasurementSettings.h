#ifndef MEASUREMENTSETTINGS_H_
#define MEASUREMENTSETTINGS_H_

#include "MeasurementType.h"
#include "IMeasurementParameter.h"

#include <vector>

namespace SSI
{
	/**
	* Represents the settings for a measurement via ISsiMeasurement::Measure
	*/
	class MeasurementSettings
	{
	public:
		/**
		* Initializes a new instance of the MeasurementSettings class.
		* @param MeasurementType type of measurement.
		*/
		MeasurementSettings(MeasurementType type);

		/**
		* Initializes a new instance of the MeasurementSettings class.
		* @param MeasurementType type of measurement.
		* @param std::vector<IMeasurementParameter*> the parameters.
		*/
		MeasurementSettings(MeasurementType type,const std::vector<IMeasurementParameter*>& parameter);
		virtual ~MeasurementSettings();

		/**
		* Get the type of measurement.
		* @return the measurement type
		*/
		MeasurementType getMeasurementType() const;

		/**
		* Get the measurement parameters.
		*@return the available measurement parameters
		*/
		std::vector<IMeasurementParameter*> getMeasurementParameter() const;
	private:
		MeasurementSettings();
		MeasurementSettings(const MeasurementSettings& copyMe);
		MeasurementSettings& operator=(const MeasurementSettings&);
		MeasurementType _type; /**< the measurement type*/
		std::vector<IMeasurementParameter*> _parameter; /**< parameters associated with the measurement type*/
	};
}
#endif