#ifndef IFRAME_H_
#define IFRAME_H_

#include "Utilities/Types/FrameType.h"

namespace SSI
{
	/**
	* Any frame that defines an angular area on a virtual sphere surrounding the instrument. Can be
	* used for scanning, panorama, etc.
	*/
	class IFrame
	{
	public:
		virtual ~IFrame();
		
		virtual bool equals(IFrame* frame) = 0;

		/**
		* Gets the type of this frame.
		* @return the type of the frame
		*/
		virtual FrameType getFrameType() const = 0;

		virtual int getNumberOfVertices() const = 0;

		virtual IFrame* clone() = 0;
	};
}
#endif