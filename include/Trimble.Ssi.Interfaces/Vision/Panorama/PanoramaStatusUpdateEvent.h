#ifndef PANORAMASTATUSUPDATEEVENT_H_
#define PANORAMASTATUSUPDATEEVENT_H_

#include "IPanoramaEstimate.h"

namespace SSI
{
	/**
	* An instance of this type is provided when a panorama is in progress.
	* It provides panorama progress and error information.
	*/
	class PanoramaStatusUpdateEvent
	{
	public:
		/**
		* Initializes a new instance of the <b>PanoramaStatusUpdateEventArgs</b> class.
		* @param estimate Estimate and progress information on the panorama.
		*/
		PanoramaStatusUpdateEvent(IPanoramaEstimate& estimate);
		virtual ~PanoramaStatusUpdateEvent();

		/**
		* Gets or sets information describing the progress of panorama.
		* @return the panorama estimate.
		*/
		const IPanoramaEstimate& getEstimate() const;
	private:
		PanoramaStatusUpdateEvent();
		PanoramaStatusUpdateEvent(const PanoramaStatusUpdateEvent& copyMe);
		PanoramaStatusUpdateEvent& operator=(const PanoramaStatusUpdateEvent&);
		IPanoramaEstimate& _estimate;
	};
}
#endif