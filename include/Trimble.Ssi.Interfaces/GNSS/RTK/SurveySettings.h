#ifndef SURVEYSETTINGS_H_
#define SURVEYSETTINGS_H_

#include "ICorrectionDataSource.h"
#include "ILinkParameter.h"
#include "IRTKFeature.h"
#include <vector>

namespace SSI
{
	/*
	* Represents survey settings.
	*
	*/
	class SurveySettings
	{
	public:
		/*
		* Initializes a new instance of the @see SurveySettings class.
		*/
		SurveySettings();

		/*
		* Initializes a new instance of the @see SurveySettings class.
		*/
		SurveySettings(const SurveySettings &surveySettings);

		~SurveySettings();

		/*
		* Initializes a new instance of the @see SurveySettings class.
		* @param linkParameter link parameter.
		* @param correctionDataSource correction data source.
		*/
		SurveySettings(ILinkParameter& linkParameter, ICorrectionDataSource& correctionDataSource);

		/*
		* Gets the link parameter.
		* @return link parameter.
		*/
		ILinkParameter* getLinkParameter() const;

		/*
		* Gets correction data source.
		* @return correction data source.
		*/
		ICorrectionDataSource* getCorrectionDataSource() const;

		/*
		* Gets the features.
		* @return std::vector<IRTKFeature*>
		*/
		std::vector<IRTKFeature*> getFeatures() const;

		/*
		* Gets the link parameter.
		* @param linkParameter link parameter.
		*/
		void setLinkParameter(ILinkParameter& linkParameter);

		/*
		* Gets correction data source.
		* @param correctionDataSource correction data source.
		*/
		void setCorrectionDataSource(ICorrectionDataSource& correctionDataSource);

		/*
		* Gets the features.
		* @return std::vector<IRTKFeature*>
		*/
		void addRTKFeatures(IRTKFeature& rtkFeature);
	protected:
		ILinkParameter *_linkParameter;
		ICorrectionDataSource *_correctionDataSource;
		std::vector<IRTKFeature*> _features;
	};
}
#endif