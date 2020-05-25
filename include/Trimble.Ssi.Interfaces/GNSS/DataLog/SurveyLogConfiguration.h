#ifndef SURVEYLOGCONFIGURATION_H
#define SURVEYLOGCONFIGURATION_H

#include "AntennaHeightConfiguration.h"

namespace SSI
{
	/**
	* Represents survey log configuration.
	*/
	class SurveyLogConfiguration
	{
	public:
		/**
		* Initializes a new instance of the @see SurveyLogConfiguration class.
		* @param antennaHeightConfiguration The antenna height configuration.
		*/
		SurveyLogConfiguration(AntennaHeightConfiguration& antennaHeightConfiguration);

		/**
		* Gets the antenna height configuration.
		* @return
		* The antenna height configuration.
		*
		*/
		AntennaHeightConfiguration* getAntennaHeightConfiguration();
		void setAntennaHeightConfiguration(AntennaHeightConfiguration& antennaHeightConfiguration);

	private:
		AntennaHeightConfiguration* _antennaHeightConfiguration;
	};
}
#endif