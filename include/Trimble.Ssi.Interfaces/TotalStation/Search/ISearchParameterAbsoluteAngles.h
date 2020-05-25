#ifndef ISEARCHPARAMETERABSOLUTEANGLES_H_
#define ISEARCHPARAMETERABSOLUTEANGLES_H_

#include "ISearchParameter.h"

namespace SSI
{
	/**
	* Represents a search parameter which defines a search window by absolute angles.
	* <seealso cref="ISsiSearch"/>
	*/
	class ISearchParameterAbsoluteAngles : public ISearchParameter
	{
	public:
		virtual ~ISearchParameterAbsoluteAngles();
	
		/**
		* Gets the horizontal start angle in radians.
		*/
		virtual double getHorizontalStartAngle() const = 0;

		/**
		* Sets the horizontal start angle in radians.
		*/
		virtual void setHorizontalStartAngle(double horizontalStartAngle) = 0;

		/**
		* Gets the horizontal stop angle in radians.
		*/
		virtual double getHorizontalStopAngle() const = 0;

		/**
		* Sets the horizontal stop angle in radians.
		*/
		virtual void setHorizontalStopAngle(double horizontalStopAngle) = 0;

		/**
		* Gets the vertical angle in radians.
		*/
		virtual double getVerticalAngle() const = 0;

		/**
		* Sets the vertical angle in radians.
		*/
		virtual void setVerticalAngle(double verticalAngle) = 0;
	};
}
#endif