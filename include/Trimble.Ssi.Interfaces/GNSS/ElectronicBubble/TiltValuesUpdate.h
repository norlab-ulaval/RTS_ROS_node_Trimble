#ifndef TILTVALUESUPDATE_H
#define TILTVALUESUPDATE_H

#include "TiltValues.h"

namespace SSI
{
	/**
	* Provides data for the @see ISsiElectronicBubbleBeta.TiltValuesChanged event.
	* @see ISsiElectronicBubbleBeta.TiltValuesChanged
	* @see ISsiElectronicBubbleBeta
	*/
	class TiltValuesUpdate
	{
	public:
		/**
		* Initializes a new instance of the @see TiltValuesUpdate class.
		* @param values The tilt values.
		*/
		TiltValuesUpdate(TiltValues values);
		TiltValuesUpdate(const TiltValuesUpdate &src);
		TiltValuesUpdate& operator=(const TiltValuesUpdate& assignMe);

		/**
		* Gets the tilt values.
		* @return The tilt values.
		*/
		TiltValues getTiltValues() const;
	private:
		TiltValues _tiltValues;
	};
}
#endif