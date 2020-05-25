#ifndef IRESOLUTIONANGULAR_H
#define IRESOLUTIONANGULAR_H
#include "IScanResolution.h"
#include "SphericalAngles.h"

namespace SSI
{
	/**
	 * Any resolution defined by horizontal and vertical angles.
	 * @see Trimble.Ssi.Interfaces.Scanner.IScanResolution
	 */
	class IResolutionAngular : public virtual IScanResolution
	{
	public:
		virtual ~IResolutionAngular();

		/**
		* Gets the horizontal and vertical resolution. Resolution is adjusted according to
		* allowed min and max.
		* @return
		* The interval in radian.
		*
		*/
		virtual SphericalAngles getIntervalInRadian() = 0;

		/**
		* Sets the horizontal and vertical resolution. Resolution is adjusted according to
		* allowed min and max.
		* @param intervalInRadian
		* The interval in radian.
		*
		*/
		virtual void setIntervalInRadian(SphericalAngles intervalInRadian) = 0;

		/**
		* Gets the minimum angular resolution value which gives the finest resolution. Should not be 0.0.
		* @return
		* The resolution minimum.
		*
		*/
		virtual SphericalAngles getResolutionMin() = 0;

		/**
		* Gets the maximum angular resolution value which gives the coarsest resolution.
		* @return
		* The resolution maximum.
		*
		*/
		virtual SphericalAngles getResolutionMax() = 0;
	};
	
}
#endif // IRESOLUTIONANGULAR_H
