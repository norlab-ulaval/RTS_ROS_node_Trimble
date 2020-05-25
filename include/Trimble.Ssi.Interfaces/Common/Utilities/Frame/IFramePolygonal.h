#ifndef IFRAMEPOLYGONAL_H
#define IFRAMEPOLYGONAL_H
#include <vector>
#include "HaVaAngles.h"
#include "IFrame.h"
#include "IFrameVerticalLimits.h"
#include "IFrameBounds.h"

namespace SSI
{
	/**
	* Any polygonal frame that defines a set of angle pairs surrounding the instrument without
	* horizontal limits. Such a frame is always considered to be “horizontal”, which means it never
	* includes a pole.
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrame
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameVerticalLimits
	* @see Trimble.Ssi.Interfaces.Utilities.Frame.IFrameBounds
	*/
	class IFramePolygonal : public virtual IFrame, public virtual IFrameVerticalLimits, public virtual IFrameBounds
	{
	public:
		virtual ~IFramePolygonal();

		/**
		* Gets a vertex list. The parameter or resulting list won't impact the polygonal frame
		* if modified. Clears the list if set to null.
		* @return
		* A List of vertices.
		*
		*/
		virtual std::vector<HaVaAngles*> getVertexList() = 0;

		/**
		* Sets a vertex list. The parameter or resulting list won't impact the polygonal frame
		* if modified. 
		* @param vertexList A List of vertices.
		*
		*/
		virtual void setVertexList(std::vector<HaVaAngles*> vertexList) = 0;

	};
}

#endif // IFRAMEPOLYGONAL_H
