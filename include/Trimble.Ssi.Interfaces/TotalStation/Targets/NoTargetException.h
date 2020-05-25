#ifndef NOTARGETEXCEPTION_H_
#define NOTARGETEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	/**
	* No target exception.
	*/
	class NoTargetException : public SsiException
	{
	public:
		/**
		* constructor.
		* @param const char* exception message
		* @param int error code
		*/
		NoTargetException(const char* msg, int errorCode);
		NoTargetException(const NoTargetException& copyMe);
	private:
		NoTargetException();
		NoTargetException& operator=(const NoTargetException&);
	};
}
#endif