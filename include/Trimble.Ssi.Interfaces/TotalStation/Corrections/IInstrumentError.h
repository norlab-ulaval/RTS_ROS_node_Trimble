#ifndef IINSTRUMENTERROR_H_
#define IINSTRUMENTERROR_H_

namespace SSI
{
	/**
	* Represents correction values for instrument errors.
	* <seealso cref="ISsiCorrectionValues"/>
	*/
	class IInstrumentError
	{
	public:
		virtual ~IInstrumentError();
	};
}
#endif