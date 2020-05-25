#ifndef ISSIRTKINITIALIZATION_H_
#define ISSIRTKINITIALIZATION_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides members to initialize the virtual reference station position
	* @remarks
	* For a brief description of features and usage of various @see ISsiInterface.
	*/
	class ISsiRTKInitialization:public ISsiInterface
	{
	public:
		virtual ~ISsiRTKInitialization();

		/**
		* Inits the position with the current rover position.
		*/
		virtual void reset()=0;
	};
}
#endif