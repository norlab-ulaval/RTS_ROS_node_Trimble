#ifndef POSITIONRATE_H_
#define POSITIONRATE_H_

namespace SSI
{
	/*
	* Represents Position Rates.
	*/
	enum PositionRate
	{
		/*
		* Position Rate is one hz.
		*/
		PositionRate_OneHz=1,

		/*
		* Position Rate is five hz.
		*/
		PositionRate_FiveHz,
	
		/*
		* Position Rate is ten hz.
		*/
		PositionRate_TenHz
	};
}
#endif