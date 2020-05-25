#ifndef ANTENNAHEIGHTCONFIGURATION_H_
#define ANTENNAHEIGHTCONFIGURATION_H_

#include "MeasurementMethod.h"

namespace SSI
{
	/**
	* Represents antenna height configuration.
	*/
	class AntennaHeightConfiguration
	{
	public:
		/**
		* Initializes a new instance of the @see AntennaHeightConfiguration class.
		* @param antennaHeight Height of the antenna.
		* @param measurementMethod The measurement method.
		*/
		AntennaHeightConfiguration(double antennaHeight, MeasurementMethod measurementMethod);

		~AntennaHeightConfiguration();

		/**
		* Gets the height of the antenna.
		* @return The height of the antenna.
		*/
		double getAntennaHeight();
		
		/**
		* Sets the height of the antenna.
		* @param The height of the antenna.
		*/
		void setAntennaHeight(double antennaHeight);

		/**
		* Gets the measurement method.
		* @return The measurement method.
		*/
		MeasurementMethod getMeasurementMethod();
	
		/**
		* Sets the measurement method.
		* @param The measurement method.
		*/
		void setMeasurementMethod(MeasurementMethod measurementMethod);
	private:
		double _antennaHeight;
		MeasurementMethod _measurementMethod;
	};
}
#endif