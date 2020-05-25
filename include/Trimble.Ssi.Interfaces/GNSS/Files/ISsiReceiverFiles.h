#ifndef ISSIRECEIVERFILES_H_
#define ISSIRECEIVERFILES_H_

#include "ISsiInterface.h"
#include "ReceiverFileListContainer.h"
#include "IFileImportProgressListener.h"
#include "IDeleteFilesProgressListener.h"

namespace SSI
{
	/**
	* Provides members to access files in GNSS receiver.
	*/
	class ISsiReceiverFiles:public ISsiInterface
	{
	public:
		virtual ~ISsiReceiverFiles();

		/**
		* register a listener for listening.
		* @param IFileImportProgressListener to listen
		*/
		virtual void addFileImportProgressListener(IFileImportProgressListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param IFileImportProgressListener to listen
		*/
		virtual void removeFileImportProgressListener(IFileImportProgressListener& listener) = 0;

		/**
		* register a listener for listening.
		* @param IDeleteFilesProgressListener to listen
		*/
		virtual void addDeleteFilesProgressListener(IDeleteFilesProgressListener& listener)= 0;

		/**
		* unsubscribe a listener from listening.
		* @param IDeleteFilesProgressListener to listen
		*/
		virtual void removeDeleteFilesProgressListener(IDeleteFilesProgressListener& listener)= 0;

		/**
		* Copies the file from receiver to the destination file location.
		* @param srcFileInfo The source file.
		* @param destFolderPath
		*/
		virtual void importFile(ReceiverFileInfo& srcFileInfo, std::string destFolderPath)=0;

		/**
		* Cancel the file import from receiver.
		*/
		virtual void cancelImport()=0;

		/**
		* Deletes the file from receiver.
		* @param receiverFileInfo The receiver file.
		*/
		virtual void deleteFile(ReceiverFileInfo& receiverFileInfo)=0;

		/**
		* Sends the file list update request.
		* @return list of files in the receiver
		*/
		virtual ReceiverFileListContainer& readFileList()=0;

		/**
		* Deletes all the file from receiver.
		*/
		virtual void deleteAllFiles()=0;

		/**
		* Cancel deletion of all the file from receiver.
		*/
		virtual void cancelDeleteAllFiles()=0;
	};
}
#endif