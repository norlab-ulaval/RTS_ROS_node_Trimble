#ifndef FRAMEDECODERTYPE_H_
#define FRAMEDECODERTYPE_H_

namespace SSI
{
	/**
	* The video and image frame decoder type
	*/
	enum FrameDecoderType
	{
		FDT_UNKNOWN = 0, /*unknown*/
		FDT_H264,		 /*H264*/
		FDT_JPEG		 /*Jpeg*/
	};
}
#endif