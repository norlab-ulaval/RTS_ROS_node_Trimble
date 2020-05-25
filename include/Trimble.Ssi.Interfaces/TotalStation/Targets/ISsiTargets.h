#ifndef ISSITARGETS_H_
#define ISSITARGETS_H_

#include "ISsiInterface.h"

#include "TargetType.h"
#include "ITarget.h"
#include "ITargetChangedListener.h"

#include <vector>

namespace SSI
{
	/**
	* Provides members to access targeting capabilities of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiTargets : public ISsiInterface
	{
	public:
		virtual ~ISsiTargets();

		/**
		* register a listener.
		* @param ITargetChangedListener the listener
		*/
		virtual void addTargetChangedListener(ITargetChangedListener& listener) = 0;

		/**
		* unsubscribe a listener.
		* @param ITargetChangedListener the listener
		*/
		virtual void removeTargetChangedListener(ITargetChangedListener& listener) = 0;

		/**
		* get all supported target types.
		* @return the supported target types
		*/
		virtual std::vector<TargetType> listSupportedTargetTypes() const = 0;

		/**
		* check if the target type supported is.
		* @param TargetType to check
		* @return true if it is otherwise false
		*/
		virtual bool isTargetSupported(TargetType targetType) const = 0;

		/**
		* get target dependent on the given target type.
		* @param TargetType to consider
		* @return the target
		*/
		virtual ITarget* createTarget(TargetType targetType) const = 0;

		/**
		* get target
		* @return the target
		*/
		virtual ITarget& getCurrentTarget() = 0;
	
		/**
		* set target
		* @param ITarget the target
		*/
		virtual void setTarget(ITarget& target) = 0;
	};
}
#endif