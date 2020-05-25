#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <exception>
#include "SsiException.h"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
namespace SSI
{
	class CustomException : public SSI::SsiException
	{
	protected:
		CustomException(const char* message, const char* exp = 0, const char* file = 0, int line = 0)
		{
			size_t size = strlen(message) + 2 + (file ? strlen(file) + 24 : 0) + (exp ? strlen(exp) : 0) + 1;
			_buf = (char*)malloc(size);
			if (file && exp)
				sprintf(_buf, "%s: %s file: %s line: %d", message, exp, file, line);
			else if (file)
				sprintf(_buf, "%s file: %s line: %d", message, file, line);
			else if (exp)
				sprintf(_buf, "%s: %s", message, exp);
			else
				sprintf(_buf, "%s", message);
		}

	public:
		virtual const char* what() const throw()
		{
			return _buf;
		}

		CustomException(const CustomException& src)
		{
			operator=(src);
		}

		virtual ~CustomException() throw()
		{
			if (_buf)
				free(_buf);
		}

		CustomException& operator=(const CustomException& src)
		{
			if (&src != this)
			{
				size_t size = strlen(src._buf) + 1;
				_buf = (char*)realloc(_buf, size);
				memcpy(_buf, src._buf, size);
			}
			return *this;
		}

	private:
		char* _buf;
	};

	class ArgumentException : public CustomException
	{
	public:
		ArgumentException(const char* exp = 0, const char* file = 0, int line = 0)
			:CustomException("ArgumentException", exp, file, line)
		{
		}
	protected:
		ArgumentException(const char* message, const char* exp , const char* file, int line)
			:CustomException(message, exp, file, line)
		{
		}
	};

	class IndexOutOfRangeException : public CustomException
	{
	public:
		IndexOutOfRangeException(const char* exp = 0, const char* file = 0, int line = 0)
			:CustomException("IndexOutOfRangeException", exp, file, line)
		{
		}
	};

	class ArgumentOutOfRangeException : public ArgumentException
	{
	public:
		ArgumentOutOfRangeException(const char* exp = 0, const char* file = 0, int line = 0)
			:ArgumentException("ArgumentOutOfRangeException", exp, file, line)
		{
		}
	};

	class InvalidOperationException : public CustomException
	{
	public:
		InvalidOperationException(const char* exp = 0, const char* file = 0, int line = 0)
			:CustomException("InvalidOperationException", exp, file, line)
		{
		}
	};

	class NotImplementedException : public CustomException
	{
	public:
		NotImplementedException(const char* exp = 0, const char* file = 0, int line = 0)
			:CustomException("NotImplementedException", exp, file, line)
		{
		}
	};
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif