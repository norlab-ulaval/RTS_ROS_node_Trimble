#ifndef INVALIDTRACKINGOBSERVATIONSEXCEPTION_H_
#define INVALIDTRACKINGOBSERVATIONSEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	class InvalidTrackingObservationsException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param bool true if tilt is out of range otherwise false
		* @param bool true if the target distance is wrong otherwise false
		* @param bool true if the is lost on a measurement otherwise false
		* @param String exception message
		* @param int error code
		*/
		InvalidTrackingObservationsException(bool isTiltOutOfRange, bool isWrongTargetDistance, bool isTargetLostOnMeasurement, const char* msg, int errorCode);
		bool isTiltOutOfRange() const;
		bool isWrongTargetDistance() const;
		bool isTargetLostOnMeasurement() const;
		InvalidTrackingObservationsException(const InvalidTrackingObservationsException& copyMe);

	private:
		InvalidTrackingObservationsException& operator=(const InvalidTrackingObservationsException&);
		InvalidTrackingObservationsException();
		bool _isTiltOutOfRange; /** is the tilt out of range */
		bool _isWrongTargetDistance; /** the target distance is wrong */
		bool _isTargetLostOnMeasurement; /** the target is lost on a measurement */
	};
}
#endif