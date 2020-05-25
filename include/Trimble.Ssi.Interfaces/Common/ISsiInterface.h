#ifndef ISSIINTERFACE_H_
#define ISSIINTERFACE_H_

#include "SsiInterfaceType.h"

namespace SSI
{
	/**
	* The base interface of all instrument interfaces which can be accessed using the ISsiInterfaceProvider::GetInterface method.
	* For a list of all possible interfaces see [Guides: Interfaces](@ref Guides_Interfaces).
	* @see ISsiInterfaceProvider
	*/
	class ISsiInterface
	{
	public:
		virtual ~ISsiInterface();

		/**
		* get the interface type.
		* @return the interface type.
		*/
		virtual SsiInterfaceType getInterfaceType() const = 0;
	};
}
#endif