#ifndef ISSIRETICLE_H_
#define ISSIRETICLE_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* The reticle brightness interface.
	*/
	class ISsiReticle : public ISsiInterface
	{
	public:
		virtual ~ISsiReticle();

		/**
		* get the reticle brightness.
		* @return the reticle brightness
		*/
		virtual int getReticleBrightness() const = 0;
	
		/**
		* set the reticle brightness.
		* @param int the brightness
		*/
		virtual void setReticleBrightness(int brightness) = 0;
	};
}
#endif