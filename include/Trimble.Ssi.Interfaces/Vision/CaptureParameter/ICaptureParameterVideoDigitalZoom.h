#ifndef ICAPUREPARAMETERVIDEODIGITALZOOM_H_
#define ICAPUREPARAMETERVIDEODIGITALZOOM_H_

#include "IVideoCaptureParameter.h"

namespace SSI
{
	/**
	* Represents a capture parameter for defining the digital video zoom of a camera.
	*/
	class ICaptureParameterVideoDigitalZoom : public IVideoCaptureParameter
	{
	public:
		virtual ~ICaptureParameterVideoDigitalZoom();

		/**
		* Gets the number of zoom steps.
		* @return the number of steps.
		*/
		virtual int getNumberOfSteps() const = 0;

		/**
		* Gets the zoom step.
		* @return The zoom step.
		*/
		virtual int getZoomStep() const = 0;
	
		/**
		* Sets the zoom step.
		* @param step The zoom step.
		*/
		virtual void setZoomStep(int step) = 0;

		/**
		* Gets the magnification of the given zoomstep.
		* @param zoomStep The zoom step.
		* @return the magnification for this zoom step.
		*/
		virtual double getMagnification(int zoomStep) const = 0;
	};
}
#endif