#ifndef ISEARCHPARAMETERTARGETMODE_H_
#define ISEARCHPARAMETERTARGETMODE_H_

#include "ISearchParameter.h"
#include "TargetMode.h"

namespace SSI
{
	/**
	* Represents a search parameter for defining the target mode of a multi target search.
	*/
	class ISearchParameterTargetMode : public ISearchParameter
	{
	public:
		virtual ~ISearchParameterTargetMode();

		/**
		* Gets the search target mode.
		* @return the multiTarget target mode
		*/
		virtual TargetMode getTargetMode() const = 0;
	
		/**
		* Sets the target mode.
		* @param targetmode. The target mode.
		*/
		virtual void setTargetMode(TargetMode targetMode) = 0;
	};
}
#endif