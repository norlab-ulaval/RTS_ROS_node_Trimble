#ifndef TARGETLOSTEXCEPTION_H_
#define TARGETLOSTEXCEPTION_H_

#include "../Common/SsiException.h"

namespace SSI
{
	class TargetLostException : public SsiException
	{
	public:
		TargetLostException(const char* message);
		virtual ~TargetLostException(void) throw ();
	};
}
#endif