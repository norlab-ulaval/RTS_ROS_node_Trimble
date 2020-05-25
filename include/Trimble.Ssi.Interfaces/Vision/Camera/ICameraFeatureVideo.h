#ifndef ICAMERAFEATUREVIDEO_H_
#define ICAMERAFEATUREVIDEO_H_

#include "ICameraFeature.h"
#include "CaptureParameter/ICaptureParameter.h"
#include "Video/IVideoStreamingUpdateListener.h"
#include "../Common/StreamingState.h"
#include "../Common/IStreamingStateChangedListener.h"
#include "Connection/ICommunicator.h"
#include "Property/ImagePropertyContainer.h"

#include <vector>

namespace SSI
{
	/**
	* This <see cref="ICameraFeature"/> is available if the Camera is capable of streaming videos
	*/
	class ICameraFeatureVideo : public ICameraFeature
	{
	public:
		virtual ~ICameraFeatureVideo();

		/**
		* register a listener for listening.
		* @param IVideoStreamingUpdateListener to listen
		*/
		virtual void addVideoStreamingUpdateListener(IVideoStreamingUpdateListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IVideoStreamingUpdateListener to listen
		*/
		virtual void removeVideoStreamingUpdateListener(IVideoStreamingUpdateListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param IVideoStreamingUpdateListener to listen
		*/
		virtual void addStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IVideoStreamingUpdateListener to listen
		*/
		virtual void removeStreamingStateChangedListener(IStreamingStateChangedListener& listener) = 0;

		/**
		* Gets the streaming state of the video.
		* @return The streaming state of the video.
		*/
		virtual StreamingState getVideoStreamingState() const = 0;

		/**
		* Starts video streaming.
		* @param captureParameters The capture parameters.
		*/
		virtual void startVideo(std::vector<ICaptureParameter*> captureParameters) = 0;

		/**
		* Stop video.
		*/
		virtual void stopVideo() = 0;

		/**
		* Changes one or several video parameters while video is started.
		* @param captureParameters The capture parameters.
		*/
		virtual void changeVideo(std::vector<ICaptureParameter*> captureParameters) = 0;

		/**
		* get an external communicator for video stream
		* @return the external communicator
		*/
		virtual Common::ICommunicator* getCommunicator() const = 0;

		/**
		* set the external communicator for video stream
		* @param communicator the external communicator
		*/
		virtual void setCommunicator(Common::ICommunicator& communicator) = 0;

		/**
		* Get Video image calibration property.
		* @param ha angle.
		* @param va angle.
		* @return the IImageProperty list
		*/
		virtual const ImagePropertyContainer* getImageCalibration(double ha, double va) const = 0;
	};
}
#endif