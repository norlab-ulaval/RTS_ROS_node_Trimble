#ifndef ISATELLITES_H_
#define ISATELLITES_H_

#include <vector>
#include "ISsiInterface.h"
#include "StreamingState.h"
#include "SatelliteMaskParameterType.h"
#include "SatelliteMask.h"
#include "ISatelliteMaskParameter.h"
#include "ISatelliteUpdateListener.h"

namespace SSI
{
	/**
	* Provides members to access the Satellite information from GNSS Receiver.
	*/
	class ISsiSatellites: public ISsiInterface
	{
	public:
		virtual ~ISsiSatellites();

		/**
		* register a listener for listening.
		*/
		virtual void addSatelliteUpdateListener(ISatelliteUpdateListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		*/
		virtual void removeSatelliteUpdateListener(ISatelliteUpdateListener& listener) = 0;

		/**
		* Lists the supported satellite mask parameter types.
		* @return Enumeration of all satellite mask parameter types.
		*/
		virtual const std::vector<SatelliteMaskParameterType>& listSupportedSatelliteMaskParameterTypes() = 0;

		/**
		* Determines whether the specified type is supported.
		* @param type The type.
		* @return true if specified type is supported.
		*/
		virtual bool isSupported(SatelliteMaskParameterType type) = 0;

		/**
		* Creates the satellite mask parameter.
		* @param satelliteMaskParameterType Type of the satellite mask parameter.
		* @return Satellite parameter mask for the given @see SatelliteMaskParameterType.
		*/
		virtual ISatelliteMaskParameter* createSatelliteMaskParameter(SatelliteMaskParameterType satelliteMaskParameterType) = 0;

		/**
		* Gets the current satellite mask from the receiver.
		*
		* @returns The current satellite mask of the connected receiver.
		*/
		virtual SatelliteMask* getSatelliteMask() = 0;

		/**
		* Sets the satellite mask.
		* @param satelliteMask The satellite mask.
		*/
		virtual void setSatelliteMask(SatelliteMask& satelliteMask) = 0;

		/**
		* Starts the satellite streaming.
		*/
		virtual void startSatelliteStreaming() = 0;

		/**
		* Stops the satellite streaming.
		*/
		virtual void stopSatelliteStreaming() = 0;

		/**
		* Sets the satellite  enabled state.
		* @param satellite The satellite.
		* @param enabled If set to true satellite will enabled
		*/
		virtual void setSatelliteEnabled(ISatellite& satellite, bool enabled) = 0;

		/**
		* Lists the supported satellite types.
		* @return List of supported satellite types.
		*/
		virtual const std::vector<SatelliteType>& listSupportedSatelliteTypes() = 0;

		/**
		* Determines whether the specified satellite type is supported.
		* @param satelliteType Type of the satellite.
		* @return True if satellite type is supported
		*/
		virtual bool isSupported(SatelliteType satelliteType) = 0;

        /**
         * Reset the satellite tracking.
         */
        virtual void resetSatelliteTracking() = 0;
	};
}
#endif