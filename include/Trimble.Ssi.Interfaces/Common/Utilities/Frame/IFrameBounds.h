#ifndef IFRAMEBOUNDS_H
#define IFRAMEBOUNDS_H

namespace SSI
{
	class IFrameRectangular;
	/**
	* Base interface to retrieve the bounding frame.
	*/
	class IFrameBounds
	{
	public:
		virtual ~IFrameBounds();
		/**
		* Gets the bounding frame. Might be null if the frame is not initialized.
		* @return
		* The bounding frame.
		*
		*/ 
		virtual IFrameRectangular* getBoundingFrame() = 0;

		/**
		* Gets the horizontal span in radian.
		* @return
		* The horizontal span.
		*
		*/ 
		virtual double getHorizontalSpan() = 0;

		/**
		* Gets the vertical span in radian.
		* @return
		* The vertical span.
		*
		*/ 
		virtual double getVerticalSpan() = 0;
	};
}

#endif // IFRAMEBOUNDS_H
