#ifndef ISSIPPMCORRECTIONPARAMETER_H_
#define ISSIPPMCORRECTIONPARAMETER_H_

#include "ISsiInterface.h"

namespace SSI
{
	/**
	* Provides members to access the parameters for the weather correction of an instrument.
	* AtmosphereCorrection depend on temperature and pressure:
	* \f$ ppm = J-( \frac{N * P}{273.16+T}) \f$
	*  * where:
	* \f$ J \f$ = Carrier wavelength
	* \f$ N \f$ = Refraction index
	* \f$ P \f$ = Pressure in millibars [mbar]
	* \f$ T \f$ = Temperature in �C [C]
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiPpmCorrectionParameter : public ISsiInterface
	{
	public:
		virtual ~ISsiPpmCorrectionParameter();
		
		/**
		* Get carrier wavelength.
		* @return the carrier wavelength
		*/
		virtual double getCarrierWaveLength() const = 0;
		
		/**
		* Get the refractive index.
		* @return the refractive index
		*/
		virtual double getRefractiveIndex() const = 0;
	};
}
#endif