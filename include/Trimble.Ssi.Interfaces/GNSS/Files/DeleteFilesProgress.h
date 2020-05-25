#ifndef DELETEFILESPROGRESS_H_
#define DELETEFILESPROGRESS_H_

namespace SSI
{
	/**
	* Provides data for the @see ISsiReceiverFiles.DeleteFilesProgress event.
	* @see ISsiReceiverFiles.DeleteFilesProgress
	* @see ISsiReceiverFiles
	*/
	class DeleteFilesProgress
	{
	public:
		/**
		* Initializes a new instance of the @see DeleteFilesProgress class.
		* @param progress The file import progress.
		*/
		DeleteFilesProgress(int progress);

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