#ifndef LEVELTILT_H_
#define LEVELTILT_H_

#include "TiltState.h"

namespace SSI
{
	/**
	* Represents a level tilt.
	* @see TiltChangedEventArgs
	* @see ISsiTilt
	*/
	class LevelTilt
	{
	public:
		/**
		* Initializes a new instance of the LevelTilt class.
		* @param TiltState The tilt state.
		* @param double The trunnion axis angle in radian.
		* @param double The sighting axis angle in radian.
		*/
		LevelTilt(TiltState state, double trunnion, double sighting);
		virtual ~LevelTilt();

		/**
		* get the tilt state
		* @return the tilt state
		*/
		TiltState getTiltState() const;

		/**
		* set the tilt state
		* @param TiltState the tilt state
		*/
		void setTiltState(TiltState tiltState);

		/**
		* get the trunnion axis angle in radian.
		* @return Radian value representing the trunnion axis angle.
		*/
		double getTrunnion() const;

		/**
		* set the trunnion axis angle in radian.
		* @param double Radian value representing the trunnion axis angle.
		*/
		void setTrunnion(double trunnion);

		/**
		* Gets the sighting axis value in radian.
		* @return Radian value representing the sighting axis angle.
		*/
		double getSighting() const;

		/**
		* Sets the sighting axis value in radian.
		* @param double Radian value representing the sighting axis angle.
		*/
		void setSighting(double sighting);
	
		/**
		* default constructor.
		*/
		LevelTilt();
		LevelTilt(const LevelTilt& copyMe);
		LevelTilt& operator=(const LevelTilt&);
	private:
		TiltState _state; /**< tilt state */
		double _trunnion; /**< trunnion axis angle in radian. */
		double _sighting; /**< sighting axis value in radian. */
	};
}
#endif