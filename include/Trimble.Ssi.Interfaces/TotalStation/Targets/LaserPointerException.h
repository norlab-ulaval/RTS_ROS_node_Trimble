#ifndef LASERPOINTEREXCEPTION_H_
#define LASERPOINTEREXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* Working mode exception.
	*/
	class LaserPointerException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param const char* exception message
		* @param int error code
		*/
		LaserPointerException(const char* msg, int errorCode);
		LaserPointerException(const LaserPointerException& copyMe);
	private:
		LaserPointerException();
		LaserPointerException& operator=(const LaserPointerException&);
	};
}
#endif