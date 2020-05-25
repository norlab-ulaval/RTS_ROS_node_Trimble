#ifndef ISSISUBSCRIPTIONS_H_
#define ISSISUBSCRIPTIONS_H_

#include "ISsiInterface.h"
#include <vector>
#include "ISubscription.h"
#include "SubscriptionType.h"

namespace SSI
{
	/**
	* Provides members to access subscriptions of an instrument.
	* @remark For a brief description of features and usage of various @see ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiSubscriptions: public ISsiInterface
	{
	public:
		virtual ~ISsiSubscriptions();

		/**
		* Lists the supported subscription types.
		* @return An enumeration of supported subscriptionTypes
		*/
		virtual std::vector<SubscriptionType> listSupportedSubscriptionTypes() const = 0;

		/**
		* Determines whether the specified subscription type has property.
		* @param subscriptionType Type of the subscription.
		* @return true if Sensor has a property of the given @see SubscriptionType; otherwise false
		*/
		virtual bool hasSubscription(SubscriptionType subscriptionType) const = 0;

		/**
		* Tries to get an @see ISubscription instance of type @see SubscriptionType
		* @param subscriptionType
		* @return An instance of the requested @see ISubscription if supported; otherwise <c>null</c>.
		*/
		virtual ISubscription* getSubscription(SubscriptionType subscriptionType) const = 0;
	};
}
#endif
