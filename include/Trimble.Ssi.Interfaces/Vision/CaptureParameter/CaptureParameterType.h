#ifndef CAPTUREPARAMETERTYPE_H_
#define CAPTUREPARAMETERTYPE_H_
namespace SSI
{
	/**
	* Represents the type of a capture parameter.
	*/
	enum CaptureParameterType
	{
		CPT_Focus,				/**< Represents a type of a capture parameter for defining the focus of a camera */
		CPT_WhiteBalance,		/**< Represents a type of a capture parameter for defining one of given white balancing presets */
		CPT_Brightness,			/**< Represents a type of a capture parameter for defining a brightness modifier */
		CPT_Sharpness,			/**< Represents a type of a capture parameter for defining a sharpness modifier */
		CPT_VideoDigitalZoom,	/**< Represents a type of a capture parameter for changing the digital video zoom level of a camera */
		CPT_OpticalZoom,		/**< Represents a type of a capture parameter for changing the digital video zoom level of a camera */
		CPT_ImageFormat,		/**< Represents a type of a capture parameter for defining the image format */
		CPT_Frame,				/**< Represents a type of a capture parameter for defining a panoramic frame */
		CPT_ImageResolution,	/**< Represents a type of a capture parameter for defining a resolution for image captures */
		CPT_VideoResolution,	/**< Represents a type of a capture parameter for defining a resolution for video updates */
		CPT_FrameRateMaximum,	/**< Represents a type of a capture parameter for defining the maximum video frame rate */
		CPT_VideoStreamMode,	/**< Represents a type of a capture parameter for defining the video stream mode UPD/RTP */
		CPT_VideoQuality,		/**< Represents a type of a capture parameter for defining the video quality */
		CPT_PanoramaOverlap,    /**< Represents a type of a capture parameter for defining the panoramic overlap */
        CPT_PanoramaFilePath,   /**< Represents a type of a capture parameter for defining the panoramic file path */
	};
}
#endif