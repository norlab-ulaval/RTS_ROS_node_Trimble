#ifndef IMAGEPROPERTYTYPE_H_
#define IMAGEPROPERTYTYPE_H_

namespace SSI
{
	/*
	* Represents the type of an image property.
	*/
	enum ImagingPropertyType
	{
		IPT_SerialNumber,					/* Represents the type of an image property carrying information about the serial number */
		IPT_CameraID,                       /* Represents the type of camera id property*/
		IPT_Orientation,					/* Represents the type of an image property carrying information about the camera orientation */
		IPT_CalibrationDate,				/* Represents the type of an image property carrying information about the calibration date of the camera */
		IPT_Calibration,                    /* Represents the type of the cameras calibration property*/
		IPT_Lens,							/* Represents the type of an image property carrying information about the camera lens */
		IPT_JpegSettings,					/* Represents the type of an image property carrying information about the jpeg properties */
		IPT_Aperture,						/* Represents the type of an image property carrying information about the aperture of the camera */
		IPT_Exposure,						/* Represents the type of an image property carrying information about the exposure of the camera */
		IPT_Flip,                           /* Represents the type of an image property carrying information about an applied flipping to the image*/
		IPT_WhiteBalance,					/* Represents the type of an image property carrying information which white balancing preset was used */
		IPT_ExposureCompensation,			/* Represents the type of an image property carrying information which exposure compensation was applied */
		IPT_Intrinsic,						/* Represents the type of an image property carrying intrinsic camera calibration properties */
		IPT_Distortion,						/* Represents the type of an image property carrying information about the distortion */
		IPT_IntrinsicImage,					/* Represents the type of an image property carrying information about the applied cropping */
		IPT_CameraSpecs,					/* Represents the type of an image property carrying information about some camera specifics */
		IPT_CameraRelativeToTelescope,		/* Represents the type of an image property carrying information about the relative orientation and translation between the camera and the telescope */
		IPT_TelescopeRelativeToInstrument,	/* Represents the type of an image property carrying information about the relative orientation and translation between the telescope and the instrument */
		IPT_EdmRelativeToTelescope,         /* Represents the type of an image property carrying information about the relative orientation and translation between the EDM beam and the telescope*/
		IPT_SlopeDistance,                  /* Represents the type of an image property carrying information about the imaging slope distance*/
		IPT_DigitalZoomStep,                /* Represents the type of an image property carrying information about the digital zoom level*/
		IPT_OpticalZoomStep,                 /* Represents the type of an image property carrying information about the optical zoom level*/
	};
}
#endif