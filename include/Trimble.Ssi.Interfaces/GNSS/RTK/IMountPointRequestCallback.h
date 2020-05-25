#ifndef IMOUNTPOINTREQUESTCALLBACK_H_
#define IMOUNTPOINTREQUESTCALLBACK_H_

#include "MountPointList.h"

namespace SSI
{
	/**
	* Listens for changed reference station.
	*/
	class IMountPointRequestCallback
	{
	public:
		virtual ~IMountPointRequestCallback();

		/**
		* receives the event message when changes occur.
		* @param mountPointList mount point list from low level driver
		* @return selected mount point
		*/
		virtual std::string selectMountPointList(const MountPointList& mountPointList) = 0;
	};
}
#endif