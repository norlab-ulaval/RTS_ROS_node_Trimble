#ifndef ICAPTUREPARAMETEROPTICALZOOM_H_
#define ICAPTUREPARAMETEROPTICALZOOM_H_

#include "IGeneralCaptureParameter.h"

namespace SSI
{
	class ICaptureParameterOpticalZoom : public IGeneralCaptureParameter
	{
	public:
		virtual ~ICaptureParameterOpticalZoom();

		/**
		* Gets the number of zoom steps.
		* @return the number of zoom steps
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
		* @return the magnification
		*/
		virtual double getMagnification(int zoomStep) const = 0;
	};
}
#endif