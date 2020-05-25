#ifndef IINSTRUMENTACCURACIESTOTALSTATION_H_
#define IINSTRUMENTACCURACIESTOTALSTATION_H_

#include "InstrumentAccuracies/IInstrumentAccuracy.h"

namespace SSI
{
	class IInstrumentAccuracyTotalStation : public IInstrumentAccuracy
	{
	public:
 		virtual ~IInstrumentAccuracyTotalStation();

		/**
		*  Gets the horizontal angle accuracy.
		*  @return the horizontal angle accuracy in radians.
		*/
		virtual double getHorizontalAngleAccuracy() const  = 0;

		/**
		*  Gets the vertical angle accuracy.
		*  @return the vertical angle accuracy in radians.
		*/
		virtual double getVerticalAngleAccuracy() const  = 0;

		/**
		*  Gets the EDM accuracy addition constant.
		*  @return the EDM accuracy addition constant in meters.
		*/
		virtual double getEDMAccuracyAdditionConstant() const  = 0;
		
		/**
		*  Gets the EDM accuracy scale factor.
		*  @return the EDM accuracy scale factor.
		*/
		virtual double getEDMAccuracyScaleFactor() const  = 0;
	};
}
#endif
