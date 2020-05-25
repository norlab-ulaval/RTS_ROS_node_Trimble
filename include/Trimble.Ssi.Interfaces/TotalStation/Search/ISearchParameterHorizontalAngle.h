#ifndef ISEARCHPARAMETERHORIZONTALANGLE_H_
#define ISEARCHPARAMETERHORIZONTALANGLE_H_

#include "ISearchParameter.h"

namespace SSI
{
	/**
	* Represents a search parameter which defines a search window by horizontal angle.
	* @see ISsiSearch
	*/
	class ISearchParameterHorizontalAngle : public ISearchParameter
	{
	public:
		virtual ~ISearchParameterHorizontalAngle();

		/**
		* Get the horizontal angle in radians.
		* @return double the angle in radians.
		*/
		virtual double getHorizontalAngle() const = 0;

		/**
		* Set the horizontal angle in radians.
		* @param double the angle in radians.
		*/
		virtual void setHorizontalAngle(double horizontalAngle) = 0;

		/**
		* Get the horizontal angle minimum in radians.
		* @return double the angle in radians.
		*/
		virtual double getHorizontalAngleMinimum() const = 0;
	
		/**
		* Get the horizontal angle maximum in radians.
		* @return double the angle in radians.
		*/
		virtual double getHorizontalAngleMaximum() const = 0;
	};
}
#endif