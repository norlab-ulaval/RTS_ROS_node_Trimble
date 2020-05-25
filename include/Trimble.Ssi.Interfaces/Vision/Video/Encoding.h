#ifndef ENCODING_H_
#define ENCODING_H_

namespace SSI
{
	/**
	* Represents the encoding algorithm of a video stream
	*/
	enum Encoding
	{
		E_None,		/**< The video stream is already decoded or never got encoded */
		E_H264		/**< The video stream is encoded with the H.264 encoding standard */
	};
}
#endif