#ifndef ISUBSCRIPTION_H_
#define ISUBSCRIPTION_H_

#include "SubscriptionType.h"
#include <string>

namespace SSI
{
	class ISubscription
	{
	public:
		virtual ~ISubscription();

		/**  Gets the type of the subscription.
		*@return The type of the subscription.
		*/
		virtual SubscriptionType getSubscriptionType()  const =0;

		/**
		*  Gets the start date.
		*  @return seconds based Unix Epoch
		*/
		virtual long long getStart() const=0;

		/**
		* Gets the expiration date.
		* @return seconds based Unix Epoch
		*/
		virtual long long getEnd() const=0;

        /**
         * Gets the additional option string of subscription.
         * @return The option string.
         */
        virtual std::string getOption() const = 0;
	};
}
#endif