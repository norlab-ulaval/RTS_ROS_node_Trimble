#ifndef SENSORBUSYEXCEPTION_H_
#define SENSORBUSYEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The sensor is busy exception.
	*/
	class SensorBusyException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		SensorBusyException(const char* message, int errorCode);
		SensorBusyException(const char * operationDescription,const char* message, int errorCode);
		SensorBusyException(const SensorBusyException& copyMe);
	private:
		SensorBusyException();
		SensorBusyException& operator=(const SensorBusyException&);
	};
}
#endif