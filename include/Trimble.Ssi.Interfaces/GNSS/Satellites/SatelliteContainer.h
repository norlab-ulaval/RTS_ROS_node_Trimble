#ifndef ISATELLITECONTAINER_H_
#define ISATELLITECONTAINER_H_

#include <vector>
#include "ISatellite.h"

namespace SSI
{
	/**
	* Represents satellite instance container.
	*/
	class SatelliteContainer
	{
	public:
		SatelliteContainer();
		SatelliteContainer(std::vector<ISatellite*>& satellites);
		virtual ~SatelliteContainer();

		/**
		* Gets the satellites.
		* @return  The satellites.
		*/
		const std::vector<ISatellite*>& getSatellites() const;

		SatelliteContainer(const SatelliteContainer& copyMe);
		SatelliteContainer& operator=(const SatelliteContainer&);
	private:
		std::vector<ISatellite*> _satellites; /** observation list */
	};
}
#endif