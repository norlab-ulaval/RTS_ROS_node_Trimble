#ifndef CALIBRATIONEXCEPTION_H_
#define CALIBRATIONEXCEPTION_H_

#include "SsiException.h"
#include <exception>

namespace SSI
{
	class CalibrationException : public SsiException
	{
	public:
		CalibrationException(const char* message);
		virtual ~CalibrationException(void) throw (){};
	};
}
#endif