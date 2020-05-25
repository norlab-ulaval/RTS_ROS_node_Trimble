#ifndef OUTOFRANGEEXCEPTION_H_
#define OUTOFRANGEEXCEPTION_H_

#include "SsiException.h"

namespace SSI
{
	/**
	* The out of range exception.
	*/
	class OutOfRangeException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		OutOfRangeException(const char* message);
		OutOfRangeException(const OutOfRangeException& copyMe);
	private:
		OutOfRangeException();
		OutOfRangeException& operator=(const OutOfRangeException&);
	};
}
#endif