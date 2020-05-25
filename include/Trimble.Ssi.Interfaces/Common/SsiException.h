#ifndef SSIEXCEPTION_H_
#define SSIEXCEPTION_H_

#include <exception>

namespace SSI
{
	/**
	* The Default SSI exception.
	*/
	class SsiException : public std::exception
	{
	public:
		/**
		* constructor.
		* @param message exception message
		* @param errorCode error code
		*/
		SsiException(const char* message, int errorCode);
		SsiException(const char * operationDescription, const char* message,  int errorCode);
		SsiException(const SsiException& copyMe);
		virtual ~SsiException() throw ();
		virtual const char* what() const throw ();
		virtual int getErrorCode() const throw ();
		virtual const char* getOperationDescirption() const throw ();
	protected:
		SsiException();
		SsiException& operator=(const SsiException& assignMe);
	private:
		const char* _message; /** the error message of th exception. */
		int _errorCode; /** the error code of the exception */
		const char * _operationDescription;
	};
}
#endif