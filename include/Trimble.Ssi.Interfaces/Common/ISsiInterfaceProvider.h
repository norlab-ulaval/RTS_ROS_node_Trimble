#ifndef ISSIINTERFACEPROVIDER_H_
#define ISSIINTERFACEPROVIDER_H_

#include "SsiInterfaceType.h"
#include "ISsiInterface.h"
#include <vector>

namespace SSI
{
	/**
	* Provides access to an implementation of an <c>interface</c> implementing the ISsiInterface.
	* For a list of all possible interfaces see [Guides: Interfaces](@ref Guides_Interfaces).
	* @see ISensor
	*/
	class ISsiInterfaceProvider
	{
	public:
		virtual ~ISsiInterfaceProvider();

		/**
		* Returns supported SSiInterfaceTypes.
		* @return an array of SSiInterfaceTypes
		*/
		virtual std::vector<SsiInterfaceType> listSupportedInterfaces() const = 0;

		/**
		* Returns an instance of SSiInterfaceType.
		* Tries to get a desired ISsiInterface interface of the type specified by the TSsiInterface type parameter.
		* @param type requested interface type
		* @return an interface instance or null
		* @see ISsiInterface
		*/
		virtual ISsiInterface* getInterface(SsiInterfaceType type) const = 0;

		/**
		* Is the interface type supported.
		* @param interfaceType SsiInterfaceType to check
		* @return if it is otherwise false
		*/
		virtual bool isInterfaceTypeSupported(SsiInterfaceType interfaceType) const = 0;
	};
}
#endif