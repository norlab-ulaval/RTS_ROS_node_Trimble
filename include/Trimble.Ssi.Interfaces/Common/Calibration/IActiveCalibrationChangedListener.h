#ifndef IACTIVECALIBRATIONCHANGEDLISTENER_H
#define IACTIVECALIBRATIONCHANGEDLISTENER_H
#include "CalibrationTypeEvent.h"

namespace SSI
{
	class IActiveCalibrationChangedListener
	{
	public:
		IActiveCalibrationChangedListener();
		virtual ~IActiveCalibrationChangedListener();
		virtual void activeCalibrationTypeChanged(CalibrationTypeEvent& calibrationTypeEvent) = 0;
	};
}

#endif // IACTIVECALIBRATIONCHANGEDLISTENER_H
