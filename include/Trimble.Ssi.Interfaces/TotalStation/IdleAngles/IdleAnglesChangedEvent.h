#ifndef IDLEANGLESCHANGEDEVENT_H_
#define IDLEANGLESCHANGEDEVENT_H_

#include "../Common/SphericalAngles.h"

namespace SSI
{
	/**
	* Message class when an event that an angle changed occurred.
	*/
	class IdleAnglesChangedEvent
	{
	public:
		/**
		* generate event with spherical angle in radian.
		* @param SphericalAngles the spherical angle to set
		*/
		IdleAnglesChangedEvent(SphericalAngles& angles);
		virtual ~IdleAnglesChangedEvent();

		/**
		* Get the spherical angle
		* @return the spherical angle
		*/
		const SphericalAngles& getAngles() const;
	private:
		IdleAnglesChangedEvent();
		IdleAnglesChangedEvent(const IdleAnglesChangedEvent& copyMe);
		IdleAnglesChangedEvent& operator=(const IdleAnglesChangedEvent&);
		SphericalAngles _angles; /**< spherical angle in radian. */
	};
}
#endif