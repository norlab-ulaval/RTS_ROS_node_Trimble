#ifndef ICAPTUREPARAMETERFRAME_H_
#define ICAPTUREPARAMETERFRAME_H_

#include "IPanoramicCaptureParameter.h"
#include "Utilities/Frame/IFrame.h"
#include "Utilities/Types/FrameType.h"
#include <vector>

namespace SSI
{
	/**
	* Represents a capture parameter for defining the frame of a panoramic capture.
	*/
	class ICaptureParameterFrame : public IPanoramicCaptureParameter
	{
	public:
		virtual ~ICaptureParameterFrame();

		/**
		* Returns the list of frame types. Basically it can be rectangular, polygonal, etc.
		* @return A list of frame types.
		*/
		virtual std::vector<FrameType> listAllFrameTypes() const = 0;

		/**
		* Creates a frame object.
		* You can retrieve a list of supported formats by calling <see cref="ListAllFrameTypes"/>.
		* @param frameType Type of the frame.
		* @return the frame object
		*/
		virtual IFrame* createFrame(FrameType frameType) = 0;

		/**
		* Gets the frame parameter.
		* @return The frame.
		*/
		virtual IFrame* getFrame() const = 0;
	
		/**
		* Sets the frame parameter.
		* @param The frame.
		*/
		virtual void setFrame(IFrame* frame) = 0;

		/**
		* Gets the default frame parameter.
		* @return The frame.
		*/
		virtual IFrame* getDefaultFrame() =0;
	};
}
#endif