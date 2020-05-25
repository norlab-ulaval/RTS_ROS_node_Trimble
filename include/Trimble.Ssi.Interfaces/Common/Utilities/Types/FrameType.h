#ifndef FRAMETYPE_H_
#define FRAMETYPE_H_

namespace SSI
{
	/**
	* Represents the type of frame.
	*/
	enum FrameType
	{
		FT_Rectangular,							/**< Rectangular frame to define min and max of vertical and horizontal scan area angles, considering smallest horizontal and vertical spans. */
		FT_RectangularHorizontalComplementary,	/**< Rectangular frame to define min and max of vertical and horizontal scan area angles, considering the biggest horizontal span and smallest vertical span. */
		FT_Polygonal,							/**< Polygonal frame to define a set of vertex describing the scan area. */
		FT_Full,								/**< Full frame to define the maximum scannable area. */
		FT_Ring,								/**< Ring frame to define a 360° scannable band arround the instrument. */
        FT_Dome,							    /**< Dome frame. */
        FT_Area   								/**< Area frame. */
	};
}
#endif