#ifndef IMEASUREMENTPARAMETERMODE_H_
#define IMEASUREMENTPARAMETERMODE_H_

#include "IMeasurementParameter.h"
#include "MeasurementMode.h"

#include <vector>

namespace SSI
{
	/**
	* Defines a measurement parameter for measurement mode settings.
	*/
	class IMeasurementParameterMode : public IMeasurementParameter
	{
	public:
		virtual ~IMeasurementParameterMode();

		/**
		* Lists the supported measurement speeds.
		* @return An enumeration of supported measurement modes.
		*/
		virtual std::vector<MeasurementMode> listSupportedMeasurementModes() const = 0;

		/**
		* is the measurement mode supported.
		* @param measurementMode MeasurementMode to check
		* @return if it is otherwise false
		*/
		virtual bool isMeasurementModeSupported(MeasurementMode measurementMode) const = 0;

		/**
		* Gets the mode of the measurement
		* @return the mode
		*/
		virtual MeasurementMode getMode() const = 0;
	
		/**
		* Sets the mode of the measurement
		* @param the mode to set
		*/
		virtual void setMode(MeasurementMode measurementMode) = 0;
	};
}
#endif