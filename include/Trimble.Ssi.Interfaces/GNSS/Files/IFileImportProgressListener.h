#ifndef IFILEIMPORTPROGRESSLISTENER_H_
#define IFILEIMPORTPROGRESSLISTENER_H_

#include "FileImportProgress.h"

namespace SSI
{
	/**
	* Listens for changed position.
	*/
	class IFileImportProgressListener
	{
	public:
		virtual ~IFileImportProgressListener();
	
		/**
		* receives the event message when changes occur.
		* @param FileImportProgressUpdate that occurred
		*/
		virtual void onFileImportProgressUpdate(const FileImportProgress& fileImportProgress) = 0;
	};
}
#endif