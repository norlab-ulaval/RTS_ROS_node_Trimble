#ifndef IDATUMRTCMPARAMETERS_H
#define IDATUMRTCMPARAMETERS_H

#include "RtcmDatumCalculationType.h"
#include "RtcmHeightIndicationType.h"

#include <string>

namespace SSI
{
	/**
	* Represents Datum RTCM Parameters.
	*/
	class IDatumRtcmParameters
	{
	public:
		virtual ~IDatumRtcmParameters();
	
		/**
		* Gets the message number.
		*
		* @return The message number.
		*/
		virtual int getMessageNumber() const = 0;

		/**
		* Gets the source name counter.
		*
		* @return The source name counter.
		*/
		virtual int getSourceNameCounter() const = 0;

		/**
		* Gets the name of the source.
		*
		* @return The name of the source.
		*/
		virtual std::string getSourceName() const = 0;

		/**
		* Gets the source key.
		*
		* @return The source key.
		*/
		virtual std::string getSourceKey() const = 0;

		/**
		* Gets the target name counter.
		*
		* @return The target name counter.
		*/
		virtual int getTargetNameCounter() const = 0;

		/**
		* Gets the name of the target.
		*
		* @return The name of the target.
		*/
		virtual std::string getTargetName() const = 0;

		/**
		* Gets the target key.
		*
		* @return The target key.
		*/
		virtual std::string getTargetKey() const = 0;

		/**
		* Gets the system ID number.
		*
		* @return The system ID number.
		*/
		virtual int getSystemIDNumber() const = 0;

		/**
		* Gets the involved transformation messages.
		*
		* @return The involved transformation messages.
		*/
		virtual int getInvolvedTransformationMessages() const = 0;

		/**
		* Gets the plate number.
		*
		* @return The plate number.
		*/
		virtual int getPlateNumber() const = 0;

		/**
		* Gets the computation indicator.
		*
		* @return The computation indicator.
		*/
		virtual RtcmDatumCalculationType getComputationIndicator() const = 0;

		/**
		* Gets the height indicator.
		*
		* @return The height indicator.
		*/
		virtual RtcmHeightIndicationType getHeightIndicator() const = 0;

		/**
		* Gets the valid area LAT origin.
		*
		* @return The valid area LAT origin.
		*/
		virtual double getValidAreaLatOrigin() const = 0;

		/**
		* Gets the valid area long origin.
		*
		* @return The valid area long origin.
		*/
		virtual double getValidAreaLongOrigin() const = 0;

		/**
		* Gets the valid area LAT extents.
		*
		* @return The valid area LAT extents.
		*/
		virtual double getValidAreaLatExtents() const = 0;

		/**
		* Gets the valid area long extents.
		*
		* @return The valid area long extents.
		*/
		virtual double getValidAreaLongExtents() const = 0;

		/**
		* Gets the DX.
		*
		* @return The DX.
		*/
		virtual double getDX() const = 0;

		/**
		* Gets the DY.
		*
		* @return The DY.
		*/
		virtual double getDY() const = 0;

		/**
		* Gets the DZ.
		*
		* @return The DZ.
		*/
		virtual double getDZ() const = 0;

		/**
		* Gets the RX.
		*
		* @return The RX.
		*/
		virtual double getRX() const = 0;

		/**
		* Gets the RY.
		*
		* @return The RY.
		*/
		virtual double getRY() const = 0;

		/**
		* Gets the RZ.
		*
		* @return The RZ.
		*/
		virtual double getRZ() const = 0;

		/**
		* Gets the SF.
		*
		* @return The SF.
		*/
		virtual double getSF() const = 0;

		/**
		* Gets the MOLO BADEKAS X.
		*
		* @return The MOLO BADEKAS X.
		*/
		virtual double getMoloBadekasX() const = 0;

		/**
		* Gets the MOLO BADEKAS Y.
		*
		* @return The MOLO BADEKAS Y.
		*/
		virtual double getMoloBadekasY() const = 0;

		/**
		* Gets the MOLO BADEKAS Z.
		*
		* @return The MOLO BADEKAS Z.
		*/
		virtual double getMoloBadekasZ() const = 0;

		/**
		* Gets the source semi major axis.
		*
		* @return The source semi major axis.
		*/
		virtual double getSourceSemiMajorAxis() const = 0;

		/**
		* Gets the source semi minor axis.
		*
		* @return The source semi minor axis.
		*/
		virtual double getSourceSemiMinorAxis() const = 0;

		/**
		* Gets the target semi major axis.
		*
		* @return The target semi major axis.
		*/
		virtual double getTargetSemiMajorAxis() const = 0;

		/**
		* Gets the target semi minor axis.
		*
		* @return The target semi minor axis.
		*/
		virtual double getTargetSemiMinorAxis() const = 0;

		/**
		* Gets the HORZ 7P quality indicator.
		*
		* @return The HORZ 7P quality indicator.
		*/
		virtual int getHorz7PQualityIndicator() const = 0;

		/**
		* Gets the VERT 7P quality indicator.
		*
		* @return The VERT 7P quality indicator.
		*/
		virtual int getVert7PQualityIndicator() const = 0;
	};
}
#endif