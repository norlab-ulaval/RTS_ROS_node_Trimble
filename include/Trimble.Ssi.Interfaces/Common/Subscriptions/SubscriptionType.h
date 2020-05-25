#ifndef SUBSCRIPTIONTYPE_H_
#define SUBSCRIPTIONTYPE_H_

namespace SSI
{
	enum SubscriptionType
	{
		/**
		* Represents the type of a Trimble xFill subscription
		*/
		SubscriptionType_xFill,

		/**
		* Represents the type of a Trimble CenterPoint RTX – Standard Initialization subscription
		*/
		SubscriptionType_RTX,

		/**
		* Represents the type of a Trimble  CenterPoint RTX - 5 Minute Initialization subscription subscription
		*/
		SubscriptionType_RTXFast,

		/**
		* Represents the type of a Trimble RangePoint RTX subscription
		*/
		SubscriptionType_RangePointRTX,

		/**
		* Represents the type of a Trimble ViewPoint RTX subscription
		*/
		SubscriptionType_ViewPointRTX,

		/**
		* Represents the type of a Trimble FieldPoint RTX subscription
		*/
		SubscriptionType_FieldPointRTX
	};
}
#endif