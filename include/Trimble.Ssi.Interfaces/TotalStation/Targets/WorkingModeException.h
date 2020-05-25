#ifndef WORKINGMODEEXCEPTION_H_
#define WORKINGMODEEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* Working mode exception.
	*/
	class WorkingModeException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param const char* exception message
		* @param int error code
		*/
		WorkingModeException(const char* msg, int errorCode);
		WorkingModeException(const WorkingModeException& copyMe);
	private:
		WorkingModeException();
		WorkingModeException& operator=(const WorkingModeException&);
	};
}
#endif