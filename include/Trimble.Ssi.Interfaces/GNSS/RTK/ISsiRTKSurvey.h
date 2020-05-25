#ifndef ISSIRTKSURVEY_H_
#define ISSIRTKSURVEY_H_

#include "ISsiInterface.h"
#include "SurveyState.h"
#include "SurveySettings.h"
#include "LinkParameterType.h"
#include "CorrectionDataSourceType.h"
#include "ICorrectionDataSource.h"
#include "ILinkParameter.h"
#include "ISurveyStateListener.h"
#include "IReferenceStationListener.h"
#include "IRTCMOnlineTransformationListener.h"
#include "IXFillStateListener.h"
#include "IXFillRTXStateListener.h"
#include "IRTKFeature.h"
#include "ICorrectionDataReceivedListener.h"
#include <vector>

namespace SSI
{
	/*
	* Provides members to access positioning data from the GNSS Receiver.
	*/
	class ISsiRTKSurvey:public ISsiInterface
	{
	public:
		virtual ~ISsiRTKSurvey();
		
		/*
		* register a listener for listening survey state.
		* @param listener ISurveyStateListener to listen.
		*/
		virtual void addSurveyStateListener(ISurveyStateListener& listener) = 0;
		
		/*
		* unregister a listener for listening survey state.
		* @param listener ISurveyStateListener to listen.
		*/
		virtual void removeSurveyStateListener(ISurveyStateListener& listener) = 0;

		/*
		* register a listener for listening reference station.
		* @param listener IReferenceStationListener to listen.
		*/
		virtual void addReferenceStationListener(IReferenceStationListener& listener) = 0;
		
		/*
		* unregister a listener for listening reference station.
		* @param listener IReferenceStationListener to listen.
		*/
		virtual void removeReferenceStationListener(IReferenceStationListener& listener) = 0;

		/*
		* register a listener for listening xFill state.
		* @param listener IXFillStateListener to listen.
		*/
		virtual void addXFillStateListener(IXFillStateListener& listener) = 0;
		
		/*
		* unregister a listener for listening xFill state.
		* @param listener IXFillStateListener to listen.
		*/
		virtual void removeXFillStateListener(IXFillStateListener& listener) = 0;

		/*
		* register a listener for listening listening xFillRTX state.
		* @param listener IXFillRTXStateListener to listen.
		*/
		virtual void addXFillRTXStateListener(IXFillRTXStateListener& listener) = 0;
		
		/*
		* unregister a listener for listening xFillRTX state.
		* @param listener IXFillRTXStateListener to listen.
		*/
		virtual void removeXFillRTXStateListener(IXFillRTXStateListener& listener) = 0;

		/*
		* register a listener for listening RTCM Online Transformation.
		* @param listener IRTCMOnlineTransformationListener to listen.
		*/
		virtual void addRTCMOnlineTransformationListener(IRTCMOnlineTransformationListener& listener) = 0;
		
		/*
		* unregister a listener for listening RTCM Online Transformation.
		* @param listener IRTCMOnlineTransformationListener to listen.
		*/
		virtual void removeRTCMOnlineTransformationListener(IRTCMOnlineTransformationListener& listener) = 0;


		/**
		* register a listener for listening RTK byte count.
		* @param ICorrectionDataReceivedListener to listen
		*/
		virtual void addCorrectionDataReceivedListener(ICorrectionDataReceivedListener& listener) = 0;

		/**
		* register a listener for listening RTK byte count.
		* @param ICorrectionDataReceivedListener to listen
		*/
		virtual void removeCorrectionDataReceivedListener(ICorrectionDataReceivedListener& listener) = 0;


		/*
		* Gets the state of the survey.
		* @return current Survey state.
		*/
		virtual SurveyState getSurveyState() const=0;

		/*
		* Gets the survey settings.
		* @return read only current  Survey settings.
		*/
		virtual SurveySettings* getSurveySettings() const=0;

		/*
		* Gets the state of XFill.
		* @return current Survey state.
		*/
		virtual XFillState getXFillState() const = 0;

		/*
		* Gets the state of XFillRTX.
		* @return current Survey state.
		*/
		virtual XFillRTXState getXFillRTXState() const = 0;

		/*
		* Lists the supported link parameter types.
		* @returns list of supported Link Parameter types.
		*/
		virtual const std::vector<LinkParameterType> listSupportedLinkParameterTypes() const=0;

		/*
		* Determines whether the specified link parameter type is supported.
		* @param linkParameterType link parameter type.
		* @return true if this Link Parameter type is supported by the receiver.
		*/
		virtual bool isSupported(LinkParameterType linkParameterType) const=0;

		/*
		* Lists the supported correction data source types.
		* @param linkParameterType link parameter type.
		* @return list of correction data source types supported for this link parameter.
		*/
		virtual const std::vector<CorrectionDataSourceType> listSupportedCorrectionDataSourceTypes(
			LinkParameterType linkParameterType)const=0;

		/*
		* Determines whether the specified correctiondatasourcetype is supported.
		* @param linkParameterType link parameter type.
		* @param correctionDataSourceType correction data source type.
		* @return true if this combination of link parameter type and correction data source type is supported by the receiver.
		*/
		virtual bool isSupported(LinkParameterType linkParameterType, CorrectionDataSourceType correctionDataSourceType) const=0;

		/*
		* Lists the supported RTK feature types.
		* @param correctionDataSourceType correction data source type.
		* @return list of RTK feature types supported for this correction data source type.
		*/
		virtual const std::vector<RTKFeatureType> listSupportedRTKFeatureTypes(
			CorrectionDataSourceType correctionDataSourceType)const=0;

		/*
		* Determines whether the specified rtkfeaturetype is supported.
		* @param correctionDataSourceType correction data source type.
		* @param rtkFeatureType RTK feature type.
		* @return true if this combination of correction data source type and RTK feature type is supported by the receiver.
		*/
		virtual bool isSupported(CorrectionDataSourceType correctionDataSourceType, RTKFeatureType rtkFeatureType) const=0;

		/*
		* Creates the link parameter.
		* @param linkParameterType link parameter type.
		* @return pointer to newly created link parameter.
		*/
		virtual ILinkParameter* createLinkParameter(LinkParameterType linkParameterType)=0;

		/*
		* Creates the correction data source.
		* @param correctionDataSourceType correction data source type.
		* @return pointer to newly created correction data source.
		*/
		virtual ICorrectionDataSource* createCorrectionDataSource(CorrectionDataSourceType correctionDataSourceType)=0;

		/*
		* Creates an RTK feature from the given RTKFeatureType.
		* @param rtkFeatureType RTK feature type.
		* @return pointer to newly created RTK feature.
		*/
		virtual IRTKFeature* createRTKFeature(RTKFeatureType rtkFeatureType)=0;

		/*
		* Starts the survey.
		* @param settings Survey setttings.
		*/
		virtual void startSurvey(SurveySettings& settings)=0;

		/*
		* Cancels the start survey.
		*/
		virtual void cancelStartSurvey()=0;

		/*
		* Ends the survey.
		*/
		virtual void endSurvey()=0;

		/*
		*  Disconnect a correction source.
		* @param Type of the link parameter.
		*/
		virtual void disconnectCorrectionSource(LinkParameterType linkParameterType)=0;
	};
}
#endif