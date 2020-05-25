#ifndef IDELETEFILESPROGRESSLISTENER_H_
#define IDELETEFILESPROGRESSLISTENER_H_

#include "DeleteFilesProgress.h"

namespace SSI
{
	/**
	* Listens for changed progress in deletion.
	*/
	class IDeleteFilesProgressListener
	{
	public:
		virtual ~IDeleteFilesProgressListener();
	
		/**
		* receives the event message when changes occur.
		* @param current Delete Progress
		*/
		virtual void onDeleteProgressUpdate(const DeleteFilesProgress& deleteProgress) = 0;
	};
}
#endif