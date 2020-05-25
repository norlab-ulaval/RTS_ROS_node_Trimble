#ifndef ISSICALIBRATION_H_
#define ISSICALIBRATION_H_

#include "ISsiInterface.h"
#include "CalibrationType.h"
#include "ICalibrationContainer.h"
#include "IActiveCalibrationChangedListener.h"

namespace SSI
{
	/**
	* Represents the <see cref="ISsiInterface"/> for handling various calibrations
	*/
	class ISsiCalibration : public ISsiInterface
	{
	public:
		virtual ~ISsiCalibration();

		/**
		* Exposes the calibration type of the active calibration, otherwise <see cref="CalibrationType.None"/>
		*/
		virtual CalibrationType getActiveCalibrationType() const = 0;

		/**
		*  Determines whether the specified calibration exists.
		* @param calibrationType Type of the calibration.
		* @return true if the calibration type is supported, otherwise false
		*/
		virtual bool hasCalibration(CalibrationType calibrationType) const = 0;

		/**
		* get all supported calibration types.
		* @return the supported target types
		*/
		virtual std::vector<ICalibrationContainer*> listSupportedCalibrations() const = 0;

		/**
		* Gets the calibration.
		* @param calibrationType Type of the calibration.
		* @return
		*/
		virtual ICalibrationContainer& getCalibration(CalibrationType calibrationType) const = 0;

		/**
		* register a listener for listening.
		* @param IActiveCalibrationChangedListener to listen
		*/
		virtual void addActiveCalibrationChangeListener(IActiveCalibrationChangedListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IActiveCalibrationChangedListener to listen
		*/
		virtual void removeActiveCalibrationChangeListener(IActiveCalibrationChangedListener& listener) = 0;
	};
}
#endif
