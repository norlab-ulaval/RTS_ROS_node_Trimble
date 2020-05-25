#ifndef IPOSITIONINGPARAMETERRATE_H_
#define IPOSITIONINGPARAMETERRATE_H_

#include "IPositioningParameter.h"
#include "PositionRate.h"
#include <vector>

namespace SSI
{
	/*
	* Represents positioning rate parameter.
	*/
	class IPositioningParameterRate: public IPositioningParameter
	{
	public:
		virtual ~IPositioningParameterRate();

		/*
		* Gets the state.
		* @return PositionRate
		*/
		virtual PositionRate getRate()=0;

		/*
		* Sets the state.
		* @param PositionRate
		*/
		virtual void setRate(PositionRate rate)=0;

		virtual const std::vector<PositionRate> listSupportedPositionRates()=0;
	};
}
#endif