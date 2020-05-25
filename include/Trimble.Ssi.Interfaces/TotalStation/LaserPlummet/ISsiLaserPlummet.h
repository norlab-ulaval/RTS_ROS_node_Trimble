#ifndef ISSILASERPLUMMET_H_
#define ISSILASERPLUMMET_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* The laser plummet brightness interface.
	*/
	class ISsiLaserPlummet : public ISsiInterface
	{
	public:
		virtual ~ISsiLaserPlummet();

		/**
		* get the laser plummet brightness.
		* @return the laser plummet brightness
		*/
		virtual int getBrightness() const = 0;
	
		/**
		* set the laser plummet brightness.
		* @param int the brightness
		*/
		virtual void setBrightness(int brightness) = 0;
	};
}
#endif