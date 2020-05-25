#ifndef ISSIVISION_H_
#define ISSIVISION_H_

#include "Camera/ICamera.h"
#include "Camera/CameraInformation.h"
#include "ISsiInterface.h"
#include "Decoder/IFrameDecoder.h"

#include <vector>

namespace SSI
{
	/**
	* This interface provides access to the different cameras. Then use the camera according to its
	* functionalities. It is up to the implementation to choose which cameras can be used in the same time.
	*/
	class ISsiVision : public ISsiInterface
	{
	public:
		virtual ~ISsiVision();

		/**
		* Returns a list of embedded cameras.
		* @return A list of embedded cameras.
		*/
		virtual std::vector<CameraInformation> listAvailableCameras() = 0;

		/**
		* Determines whether the specified type is supported.
		* @param cameraInformation The camera information.
		* @return <c>true</c> if the camera exists, otherwise <c>false</c>.
		*/
		virtual bool hasCamera(CameraInformation cameraInformation) = 0;

		/**
		* Gets a unique camera instance given a camera identifier.
		* @param cameraId Identifier of camera to retrieve. You can retrieve a list of embedded cameras by calling <see cref="ListAvailableCameras" />
		* @return A camera instance.
		*/
		virtual ICamera* getCamera(CameraInformation cameraId) = 0;

		/**
		* Create a FrameDecoder for Image and Video.
		* @param type the FrameDecoderType
		* @return a FrameDecoder instance.
		*/
		virtual IFrameDecoder* CreateFrameDecoder(FrameDecoderType type) = 0;
	};
}
#endif