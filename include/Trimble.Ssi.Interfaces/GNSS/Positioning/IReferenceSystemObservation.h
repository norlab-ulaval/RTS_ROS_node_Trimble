#ifndef IREFERENCESYSTEMOBSERVATION_H_
#define IREFERENCESYSTEMOBSERVATION_H_

#include "IGNSSObservation.h"
#include "ReferenceSystem.h"
#include "RTK/ReferenceFrame.h"
#include "TectonicPlate.h"

namespace SSI
{
	/*
	* Represents a reference system observation.
	*/
	class IReferenceSystemObservation: public IGNSSObservation
	{
	public:
		virtual ~IReferenceSystemObservation();
	
		/*
		* Gets the reference frame.
		* @return ReferenceFrame
		*/
		virtual ReferenceFrame getReferenceFrame()=0;

		/*
		* Gets the tectonic plate.
		* @return TectonicPlate
		*/
		virtual TectonicPlate getTectonicPlate() = 0;

		/*
		* Gets the Epoch.
		* @return Epoch
		*/
		virtual double getEpoch() = 0;
	};
}
#endif