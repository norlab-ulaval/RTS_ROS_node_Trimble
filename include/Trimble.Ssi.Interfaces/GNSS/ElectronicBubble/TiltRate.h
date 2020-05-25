#ifndef TILTRATE_H_
#define TILTRATE_H_

namespace SSI
{
	/*
	* Represents Tilt Rates.
	*/
	enum TiltRate
	{
		/*
		* Tilt Rate is one hz.
		*/
		TiltRate_OneHz=1,

		/*
		* Tilt Rate is five hz.
		*/
		TiltRate_FiveHz,
	
		/*
		* Tilt Rate is ten hz.
		*/
		TiltRate_TenHz
	};
}
#endif