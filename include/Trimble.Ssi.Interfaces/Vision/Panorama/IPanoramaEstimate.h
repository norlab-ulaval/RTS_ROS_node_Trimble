#ifndef IPANORAMAESTIMATE_H_
#define IPANORAMAESTIMATE_H_
#include "TimeEstimate.h"

namespace SSI
{
	/**
	* Interface for panorama estimates.
	*/
	class IPanoramaEstimate
	{
	public:
		virtual ~IPanoramaEstimate();

		/**
		* Gets the number of images completed.
		* @return The number of images completed.
		*/
		virtual int getImagesCompleted() const = 0;

		/**
		* Gets the total image number.
		* @return images total
		*/
		virtual int getImagesTotal() const = 0;

		/**
		 * Gets the time estimate for the panorama duration.
		 * @return The time estimate
		 */
		virtual TimeEstimate& getTimeEstimate() const = 0;
	};
}
#endif