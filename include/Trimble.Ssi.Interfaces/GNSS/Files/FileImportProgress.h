#ifndef FILEIMPORTPROGRESS_H_
#define FILEIMPORTPROGRESS_H_

namespace SSI
{
	/**
	* Provides data for the @see ISsiReceiverFiles.FileImportProgress event.
	* @see ISsiReceiverFiles.FileImportProgress
	* @see ISsiReceiverFiles
	*/
	class FileImportProgress
	{
	public:
		/**
		* Initializes a new instance of the @see FileImportProgress class.
		* @param progress The file import progress.
		*/
		FileImportProgress(int progress);

		/**
		* Gets the progress.
		* @return The progress.
		*/
		int getProgress();

		/**
		* Sets the progress.
		* @return The progress.
		*/
		void setProgress(int progress);
	private:
		int _progress;
	};
}
#endif