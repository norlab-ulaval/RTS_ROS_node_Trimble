#ifndef ISCANESTIMATE_H
#define ISCANESTIMATE_H
#include "TimeEstimate.h"

namespace SSI
{
	/**
	* Interface to hold scan estimates.
	*/
	class IScanEstimate
	{
	public:
		virtual ~IScanEstimate();


		/**
		* Gets the time estimate for the scan duration.
		* @return
		* The time estimate.
		*
		*/
		virtual TimeEstimate& getTimeEstimate() = 0;

		/**
		* Gets the remaining points number.
		* @return
		* The points number remaining.
		*
		*/
		virtual int getPointsNumberRemaining() = 0;

		/**
		* Gets the scanned points number since the first start of the scan,
		* independently of a pause/resume.
		* @return
		* The points number scanned.
		*
		*/
		virtual int getPointsNumberScanned() = 0;

		/**
		* Gets the points number predicted, independently of a pause/resume.
		* @return
		* The points number predicted.
		*
		*/
		virtual int getPointsNumberPredicted() = 0;
	};
}

#endif // ISCANESTIMATE_H
