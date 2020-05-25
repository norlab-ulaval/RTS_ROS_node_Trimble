#ifndef INVALIDMEASUREMENTEXCEPTION_H_
#define INVALIDMEASUREMENTEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* Invalid measurement exception.
	*/
	class InvalidMeasurementException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param bool true if tilt is out of range otherwise false
		* @param bool true if the standard deviation is not reached otherwise false
		* @param bool true if the target distance is wrong otherwise false
		* @param String exception message
		* @param int error code
		*/
		InvalidMeasurementException(bool isTiltOutOfRange, bool isWrongTargetDistance, const bool isStdDevNotReached, const char* msg, int errorCode);

		/**
		* is the tilt out of range ?.
		* @return true if the target distance is wrong otherwise false
		*/
		bool isTiltOutOfRange() const;

		/**
		*  is the target distance wrong ?.
		*  @return true if the target distance is wrong otherwise false
		*/
		bool isWrongTargetDistance() const;

		/**
		* is the standard deviation reached?.
		* @return true if the standard deviation is reached otherwise false
		*/
		bool isStdDevNotReached() const;
		InvalidMeasurementException(const InvalidMeasurementException& copyMe);

	private:
		InvalidMeasurementException();
		InvalidMeasurementException& operator=(const InvalidMeasurementException&);
		bool _isTiltOutOfRange; /**< is the tilt out of range */
		bool _isWrongTargetDistance; /**< the target distance is wrong */
		bool _isStdDevNotReached; /**< is the standard deviation reached */
	};
}
#endif