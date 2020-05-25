#ifndef RESOLUTION_H_
#define RESOLUTION_H_

namespace SSI
{
	/**
	* Represents a resolution an provides predefined resolutions.
	*/
	enum Resolution
	{
		R_FiveMP,			/**< Represents a Five Mega pixel resolution. 2592x1944 */
		R_QXGA,				/**< Represents a QXGA resolution. 2048x1536 */
		R_XGA,				/**< Represents a XGA resolution. 1024x768 */
		R_XGA4TH,			/**< Represents a 4th of a XGA resolution. 512x384 */
		R_XGA16TH,			/**< Represents a 16th of a XGA resolution. 256x192 */
		R_WVGA752x480,		/**< Represents a WVGA resolution 752x480 */
		R_WVGA4TH376x240,	/**< Represents a 4th of a WVGA resolution 376x240 */
		R_WVGA16TH184x120,	/**< Represents a 16th of a WVGA resolution 184x120 */
		R_VGA,				/**< Represents a VGA resolution. 640x480 */
		R_QQVGA160x120,		/**< Represents a QQVGA resolution. 160x120 */
		R_QVGA320x240		/**< Represents a QVGA resolution. 320x240 */

	};
}
#endif