#ifndef IFRAMEVERTICALLIMITS_H
#define IFRAMEVERTICALLIMITS_H

namespace SSI
{
	/**
	 * Any frame that is limited in term of vertical angle. Any derived object should adapt the
	 * frame with regards to these vertical limits.
	 */
	class IFrameVerticalLimits 
	{
	public:
		virtual ~IFrameVerticalLimits();

		/**
		 * Gets the minimum vertical limit in radian. Z axis reference.
		 * @return The vertical limit minimum.
		 */
		virtual double getVerticalLimitMin() = 0;

		/**
		* Gets the maximum vertical limit in radian. Z axis reference.
		* @return The vertical limit maxium.
		*/
		virtual double getVerticalLimitMax() = 0;

	};
}

#endif // IFRAMEVERTICALLIMITS_H
