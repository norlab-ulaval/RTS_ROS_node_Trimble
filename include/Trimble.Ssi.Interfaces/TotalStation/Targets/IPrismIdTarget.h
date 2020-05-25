#ifndef IPRISMIDTARGET_H_
#define IPRISMIDTARGET_H_

#include "IPrismAdvancedTarget.h"
#include <vector>

namespace SSI
{
	/** Represents a responsive prism target with an id.
	* @see ISsiTargets
	*/
	class IPrismIdTarget : public IPrismAdvancedTarget
	{
	public:
		virtual ~IPrismIdTarget();

		/** Get the target ID.
		* @return ID of the target.
		*/
		virtual int getTargetId() const = 0;

		/** Sets the target ID.
		*@param targetId of the target.
		*/
		virtual void setTargetId(int targetId) = 0;

		/** Returns a list of all valid target ids.
		* @return A list of all valid target ids.
		*/
		virtual std::vector<int> listSupportedTargetIds() const = 0;

		/**
		* is the target ID supported ?
		* @param target ID to check
		* @return true if it is otherwise false
		*/
		virtual bool isTargetIdSupported(int targetId) const = 0;
	};
}
#endif