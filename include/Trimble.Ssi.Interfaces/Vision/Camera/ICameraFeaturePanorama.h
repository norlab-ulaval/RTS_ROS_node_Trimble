#ifndef ICAMERAFEATUREPANORAMA_H_
#define ICAMERAFEATUREPANORAMA_H_

#include "ICameraFeature.h"
#include "CaptureParameter/IPanoramicCaptureParameter.h"
#include <vector>
#include "Panorama/IPanoramaImageListener.h"
#include "Panorama/IPanoramaStateListener.h"
#include "Panorama/IPanoramaStatusListener.h"

namespace SSI
{

	/**
	* This <see cref="ICameraFeature"/> is available if the camera is capable of taking panorama Pictures.
	*/
	class ICameraFeaturePanorama : public ICameraFeature
	{
	public:
		virtual ~ICameraFeaturePanorama();
		/**
		* register a listener for listening.
		* @param panoramaImageListener to listen
		*/
		virtual void addPanoramaImageListener(IPanoramaImageListener& panoramaImageListener)=0;

		/**
		* unsubscribe a listener from listening.
		* @param panoramaImageListener to listen
		*/
		virtual void removePanoramaImageListener(IPanoramaImageListener& panoramaImageListener) = 0;

		/**
		* register a listener for listening.
		* @param panoramaStateListener to listen
		*/
		virtual void addPanoramaStateListener(IPanoramaStateListener& panoramaStateListener) = 0;
		/**
		* unsubscribe a listener from listening.
		* @param panoramaStateListener to listen
		*/
		virtual void removePanoramaStateListener(IPanoramaStateListener& panoramaStateListener) = 0;

		/**
		* register a listener for listening.
		* @param panoramaStatusListener to listen
		*/
		virtual void addPanoramaStatusListener(IPanoramaStatusListener& panoramaStatusListener) = 0;
		/**
		* unsubscribe a listener from listening.
		* @param panoramaStatusListener to listen
		*/
		virtual void removePanoramaStatusListener(IPanoramaStatusListener& panoramaStatusListener) = 0;

		/**
		* Takes a panorama. On completion the given delegate will be called.
		* @param captureParameters the capture parameters
		*/
		virtual void startPanorama(std::vector<ICaptureParameter*> captureParameters) = 0;
	
		/**
		* Stops a panorama that is in progress. On completion the given delegate will be called.
		*/
		virtual void stopPanorama() = 0;

		/**
		* Use this method to get panorama estimates in term of time, number of images, etc.
		* @return The panorama estimate.
		*/
		virtual IPanoramaEstimate* estimatePanorama(std::vector<ICaptureParameter*> captureParameters) = 0;

		virtual PanoramaState getPanoramaState()=0;
	};
}
#endif