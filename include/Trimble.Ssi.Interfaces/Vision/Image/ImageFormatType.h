#ifndef IMAGEFORMATTYPE_H_
#define IMAGEFORMATTYPE_H_

namespace SSI
{
	/**
	* Represents an image format
	*/
	enum ImageFormatType
	{
		IFT_Jpeg,					/**< Type of image format for jpeg image. This format has a file header. */
		IFT_Bmp,					/**< Type of image format for bmp image. This format has a file header. */
		IFT_RgbaPixels32NoHeader,	/**< Type image format for pixel arrays of rgba bytes without any header. */
		IFT_RGB_Tiff,				/**< Type of image format for RGB tiff image. */
		IFT_Raw,					/**< Type of image format for RAW image. */
		IFT_H264,					/**< Type of image format for h264 frame */
	};
}
#endif