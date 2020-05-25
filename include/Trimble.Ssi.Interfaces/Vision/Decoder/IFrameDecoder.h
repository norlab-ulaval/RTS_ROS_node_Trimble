#ifndef IFRAMEDECODER_H_
#define IFRAMEDECODER_H_

#include "FrameDecoderType.h"

namespace SSI
{
	/**
	* The video and image frame decoder
	*/
	class IFrameDecoder
	{
	public:
		virtual ~IFrameDecoder();

		/**
		* Get the decoder type
		* @return the decoder type
		*/
		virtual FrameDecoderType Type() const = 0;

		/**
		* Initiates the decoder
		* @param width the expected image width
		* @param height the expected image height
		*/
		virtual void InitDecoder(int width, int height) = 0;

		/**
		* Close the decoder
		*/
		virtual void CloseDecoder() = 0;

		/**
		* DecodeFrame one frame
		* @param framebuffer the input buffer
		* @param framelength the input buffer length
		* @param ARGBbuffer  the output buffer (ARGB)
		* @param ARGBlength  the output buffer length
		* @return the decoded length
		*/
		virtual unsigned int DecodeFrame(unsigned char* framebuffer, unsigned int framelength, unsigned char* ARGBbuffer, unsigned int ARGBlength) const = 0;
	};
}
#endif