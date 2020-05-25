#ifndef IDIRECTREFLEXADVANCEDTARGET_H_
#define IDIRECTREFLEXADVANCEDTARGET_H_

#include "IDirectReflexTarget.h"

namespace SSI
{
	/** Represents a direct reflex target whose range can be limited.
	* If values measured using the <see cref="ISsiMeasurement"/> interface are not within
	* <see cref="DRSearchRangeMin"/> and <see cref="DRSearchRangeMax"/> the measurement will fail.
	* @see ISsiTargets
	*/
	class IDirectReflexAdvancedTarget : public IDirectReflexTarget
	{
	public:
		virtual ~IDirectReflexAdvancedTarget();

		/** Gets a value indicating whether to use weak signals for DR measurements or not.
		* @return <c>true</c> if using weak signal; otherwise, <c>false</c>.
		*/
		virtual bool isUsingWeakSignal() const = 0;
	
		/** Sets a value indicating whether to use weak signals for DR measurements or not.
		* @param weakSignal <c>true</c> if using weak signal; otherwise, <c>false</c>.
		*/
		virtual void useWeakSignal(bool weakSignal) = 0;

		/** Gets the limit of the DR minimum distance.
		* @return Minimum search range limit.
		*/
		virtual double getDRSearchRangeMinLimit() const = 0;

		/** Gets the limit of the DR maximum distance.
		* @return Maximum search range limit.
		*/
		virtual double getDRSearchRangeMaxLimit() const = 0;

		/** Gets DR minimum distance for the current DR measurement.
		* @return Minimum search range for the current measurement.
		*/
		virtual double getDRSearchRangeMin() const = 0;

		/** Sets DR minimum distance for the current DR measurement.
		* @param rangeMin Minimum search range for the current measurement.
		*/
		virtual void setDRSearchRangeMin(double rangeMin) = 0;

		/** Gets DR maximum distance for the current DR measurement.
		* @return Maximum search range for the current measurement.
		*/
		virtual double getDRSearchRangeMax() const = 0;

		/** Sets DR maximum distance for the current DR measurement.
		* @param rangeMax Maximum search range for the current measurement.
		*/
		virtual void setDRSearchRangeMax(double rangeMax) = 0;
	};
}
#endif