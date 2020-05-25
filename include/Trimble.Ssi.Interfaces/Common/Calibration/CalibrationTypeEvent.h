#ifndef CALIBRATIONTYPEEVENT_H
#define CALIBRATIONTYPEEVENT_H
#include "CalibrationType.h"

namespace SSI
{
	class CalibrationTypeEvent
	{
	public:
		CalibrationTypeEvent(CalibrationType calibrationType);
		virtual ~CalibrationTypeEvent();
		CalibrationType getCalibrationType();
	protected:
		CalibrationType _calibrationType;
	};

	
}
#endif // CALIBRATIONTYPEEVENT_H
