#ifndef CAMERAINFORMATION_H_
#define CAMERAINFORMATION_H_

namespace SSI
{
	/**
	 * Specifies the camera information identifying a physical or logical camera.
	 */
	enum CameraInformation
	{
		/**
		 *  Default instrument camera
		 */
		CI_Default,

		/**
		 *  Telecamera supports Focus and Optical Zoom
		 */
		CI_Tele,

		/**
		 *  Measurecamera
		 */
		CI_Measure,

		/**
		 *  Overviewcamera
		 */
		CI_Overview,

		/**
		 *  Panoramacamera
		 */
		CI_Panorama,

		/**
		 *  Plummetcamera
		 */
		CI_Plummet,
	};
}
#endif