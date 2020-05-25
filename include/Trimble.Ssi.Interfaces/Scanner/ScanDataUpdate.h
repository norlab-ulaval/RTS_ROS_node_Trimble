#ifndef SCANDATAUPDATE_H
#define SCANDATAUPDATE_H
#include <vector>
#include "Utilities/Point/I3DPoint.h"
#include "Points/PointFormatType.h"

namespace SSI
{
	class ScanDataUpdate
	{
	public:
		ScanDataUpdate(std::vector<I3DPoint*>  pointSet, PointFormatType pointFormateType);
		virtual ~ScanDataUpdate();
		/**
		 * Gets a point collection.
		 * @return The point set
		 */
		std::vector<I3DPoint*> getPointSet();

		/**
		 * Point format type.
		 * @return The type of the point format.
		 */
		PointFormatType getPointFormatType();
	private:
		std::vector<I3DPoint*>  _pointSet;
		PointFormatType _pointFormatType;
	};
}

#endif // SCANDATAUPDATE_H
