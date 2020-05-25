#ifndef CAMERAFEATURETYPE_H_
#define CAMERAFEATURETYPE_H_

namespace SSI
{
	/**
	* The Type of a camera feature.
	*/
	enum CameraFeatureType
	{
		CFT_Image,		/**< Represents the image camera feature. */
		CFT_Panorama,	/**< Represents the panoramic camera feature. */
		CFT_Video,		/**< Represents the video camera feature. */
		CFT_Focus		/**< Represents the focus camera feature. */
	};
}
#endif