#ifndef CalibrationProgress_H_
#define CalibrationProgress_H_

namespace SSI
{
	/**
	* Provides data for the @see ISsiElectronicBubble.CalibrationProgress event.
	* @see ISsiElectronicBubble.CalibrationProgress
	* @see ISsiElectronicBubble
	*/
	class CalibrationProgress
	{
	public:
		/**
		* Initializes a new instance of the @see CalibrationProgress class.
		* @param progress The file import progress.
		*/
		CalibrationProgress(int progress);

		/**
		* Gets the progress.
		* @return
		* The progress.
		*/
		int getProgress() const;

		/**
		* Sets the progress.
		* @return
		* The progress.
		*/
		void setProgress(int progress);
	private:
		int _progress;
	};
}
#endif
