#ifndef OUTPUTRATE_H
#define OUTPUTRATE_H

namespace SSI
{
	/**
	*  Showing the NMEAOutputRate.
	*/
	enum OutputRate
	{
		/**
		*  The OutputRate: Off.
		*/
		OutputRate_Off,

		/**
		*  The OutputRate: 20Hz.
		*/
		OutputRate_TwentyHz,

		/**
		*  The OutputRate: 10Hz.
		*/
		OutputRate_TenHz,

		/**
		*  The OutputRate: 5Hz.
		*/
		OutputRate_FiveHz,

		/**
		*  The OutputRate: 2Hz.
		*/
		OutputRate_TwoHz,

		/**
		*  The OutputRate: 1Hz.
		*/
		OutputRate_OneHz,

		/**
		*  The OutputRate: 2Seconds.
		*/
		OutputRate_TwoSeconds,

		/**
		*  The OutputRate: 5Seconds.
		*/
		OutputRate_FiveSeconds,

		/**
		*  The OutputRate: 10Seconds.
		*/
		OutputRate_TenSeconds,

		/**
		*  The OutputRate: 15Seconds.
		*/
		OutputRate_FifteenSeconds,

		/**
		*  The OutputRate: 30Seconds.
		*/
		OutputRate_ThirtySeconds,

		/**
		*  The OutputRate: 60Seconds.
		*/
		OutputRate_SixtySeconds,

		/**
		*  The OutputRate: 5Minutes.
		*/
		OutputRate_FiveMinutes,

		/**
		*  The OutputRate: 10Minutes.
		*/
		OutputRate_TenMinutes,
	};
}
#endif