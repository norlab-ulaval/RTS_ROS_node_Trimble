#ifndef SATELLITEMASK_H_
#define SATELLITEMASK_H_

#include <vector>
#include "ISatelliteMaskParameter.h"

namespace SSI
{
	/**
	* Represents a mask, that defines which Satellites should get tracked.
	*/
	class SatelliteMask
	{
	public:

		/**
		* Initializes a new instance of the @see SatelliteMask class.
		*/
		SatelliteMask();
		virtual ~SatelliteMask();

		/**
		* Gets an enumeration of configured @see ISatelliteMaskParameter instances.
		* @return list of parameters
		* The @see ISatelliteMaskParameter instances.
		*/
		const std::vector<ISatelliteMaskParameter*>& getParameters();

		/**
		* Appends to the enumeration of configured @see ISatelliteMaskParameter instances.
		* @param parameter The parameter to add.
		*/
		void addParameter(ISatelliteMaskParameter* parameter);
	private:
		std::vector<ISatelliteMaskParameter*> _parameters;
	};
}
#endif