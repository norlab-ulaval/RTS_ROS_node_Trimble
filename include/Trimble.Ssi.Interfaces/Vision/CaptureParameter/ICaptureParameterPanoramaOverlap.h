#ifndef ICAPTUREPARAMETERPANORAMAOVERLAP_H
#define ICAPTUREPARAMETERPANORAMAOVERLAP_H
#include "IPanoramicCaptureParameter.h"

namespace SSI
{
	/**
	* Represents the parameter for specifying the overlap of the images
	* @see Trimble.Ssi.Interfaces.Vision.CaptureParameter.IPanoramicCaptureParameter
	*/
	class ICaptureParameterPanoramaOverlap :public IPanoramicCaptureParameter
	{
	public:
		virtual ~ICaptureParameterPanoramaOverlap();

		/**
		* Gets the vertical and horizontal overlap of the panorama images.
		* @return
		* The overlap.[0-100]
		*
		* @remarks
		* Should be between 0 and 100
		*/
		virtual int getOverlap() =0;

		/**
		* Sets the vertical and horizontal overlap of the panorama images.
		* @return
		* The overlap.[0-100]
		*
		* @remarks
		* Should be between 0 and 100
		*/
		virtual void setOverlap(int overlap)=0;
	};
}

#endif // ICAPTUREPARAMETERPANORAMAOVERLAP_H
