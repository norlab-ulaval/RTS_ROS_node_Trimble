#ifndef ICAMERAIMAGEPROPERTYCALIBRATIONDATE_H_
#define ICAMERAIMAGEPROPERTYCALIBRATIONDATE_H_

#include "IImagingProperty.h"

namespace SSI
{
	/**
	* Represents an image property carrying information about the cameras last calibration date.
	*/
	class ICameraImagePropertyCalibrationDate : public IImagingProperty
	{
	public:
		virtual ~ICameraImagePropertyCalibrationDate();
	
		/**
		* Gets the calibration date.
		* @return the calibration date.
		*/
		virtual long long getCalibrationDate() const = 0;
	};
}
#endif