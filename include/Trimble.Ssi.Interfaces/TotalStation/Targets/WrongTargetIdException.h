#ifndef WRONGTARGETIDEXCEPTION_H_
#define WRONGTARGETIDEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* Working mode exception.
	*/
	class WrongTargetIdException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param const char* exception message
		* @param int error code
		*/
		WrongTargetIdException(const char* msg, int errorCode);
		WrongTargetIdException(const WrongTargetIdException& copyMe);
	private:
		WrongTargetIdException();
		WrongTargetIdException& operator=(const WrongTargetIdException&);
	};
}
#endif