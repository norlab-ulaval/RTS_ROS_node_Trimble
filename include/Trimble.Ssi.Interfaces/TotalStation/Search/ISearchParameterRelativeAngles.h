#ifndef ISEARCHPARAMETERRELATIVEANGLES_H_
#define ISEARCHPARAMETERRELATIVEANGLES_H_

#include "ISearchParameter.h"

namespace SSI
{
	/**
	* Represents a search parameter which defines a search window by relative angles.
	* @see ISsiSearch
	*/
	class ISearchParameterRelativeAngles : public ISearchParameter
	{
	public:
		virtual ~ISearchParameterRelativeAngles();

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
		* Get the vertical angle in radians.
		* @return double the angle in radians.
		*/
		virtual double getVerticalAngle() const = 0;

		/**
		* Set the vertical angle in radians.
		* @param double the angle in radians.
		*/
		virtual void setVerticalAngle(double verticalAngle) = 0;

		/**
		* Get the vertical angle minimum in radians.
		* @return double the angle in radians.
		*/
		virtual double getVerticalAngleMinimum() const = 0;

		/**
		* Get the vertical angle maximum in radians.
		* @return double the angle in radians.
		*/
		virtual double getVerticalAngleMaximum() const = 0;

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