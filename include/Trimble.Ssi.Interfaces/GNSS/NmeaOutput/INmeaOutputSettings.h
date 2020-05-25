#ifndef INMEAOUTPUTSETTINGS_H
#define INMEAOUTPUTSETTINGS_H

#include "NmeaDevicePort.h"
#include "OutputRate.h"

namespace SSI
{
	/**
	*  Displaying the Nmea Output Settings.
	*/
	class INmeaOutputSettings
	{
	public:
		virtual ~INmeaOutputSettings();

		/**
		*  Gets the device port.
		*  @return port the NmeaDevicePort
		*/
		virtual NmeaDevicePort getDevicePort() const = 0;

		/**
		*  Sets the device port.
		*  @param port the NmeaDevicePort
		*/
		virtual void setDevicePort(NmeaDevicePort port) = 0;

		/**
		*  Get the GGA output rate.
		*  Time, Position and Fix Related Data.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGGAOutputRate() const = 0;

		/**
		*  Set the GGA output rate.
		*  Time, Position and Fix Related Data.
		*  @param rate the OutputRate
		*/
		virtual void setGGAOutputRate(OutputRate rate) = 0;

		/**
		*  Get the GST output rate.
		*  Position Error Statistics.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGSTOutputRate() const = 0;

		/**
		*  Set the GST output rate.
		*  Position Error Statistics.
		*  @param rate the OutputRate
		*/
		virtual void setGSTOutputRate(OutputRate rate) = 0;

		/**
		*  Get the GSV output rate.
		*  Satellite Information.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGSVOutputRate() const = 0;

		/**
		*  Set the GSV output rate.
		*  Satellite Information.
		*  @param rate the OutputRate
		*/
		virtual void setGSVOutputRate(OutputRate rate) = 0;

        /**
		*  Get the RMC output rate.
        *  Position, Velocity, and Time.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getRMCOutputRate() const = 0;

		/**
		*  Set the RMC output rate.
        *  Position, Velocity, and Time.
		*  @param rate the OutputRate
		*/
		virtual void setRMCOutputRate(OutputRate rate) = 0;


        /**
		*  Get the GGK output rate.
        *  Time, position, position type, and DOP values.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGGKOutputRate() const = 0;

		/**
		*  Set the GGK output rate.
        *  Time, position, position type, and DOP values.
		*  @param rate the OutputRate
		*/
		virtual void setGGKOutputRate(OutputRate rate) = 0;

        /**
		*  Get the VTG output rate.
        *  Actual track made good and speed over ground.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getVTGOutputRate() const = 0;

		/**
		*  Set the VTG output rate.
        *  Actual track made good and speed over ground.
		*  @param rate the OutputRate
		*/
		virtual void setVTGOutputRate(OutputRate rate) = 0;

        /**
		*  Get the ZDA output rate.
        *  UTC day, month, and year, and local time zone offset.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getZDAOutputRate() const = 0;

		/**
		*  Set the ZDA output rate.
        *  UTC day, month, and year, and local time zone offset.
		*  @param rate the OutputRate
		*/
		virtual void setZDAOutputRate(OutputRate rate) = 0;

                /**
		*  Get the GLL output rate.
        *  Position data: position fix, time of position fix, and status.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGLLOutputRate() const = 0;

		/**
		*  Set the GLL output rate.
        *  Position data: position fix, time of position fix, and status.
		*  @param rate the OutputRate
		*/
		virtual void setGLLOutputRate(OutputRate rate) = 0;

                /**
		*  Get the GNS output rate.
        *  GNS Fix data.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGNSOutputRate() const = 0;

		/**
		*  Set the GNS output rate.
        *  GNS Fix data.
		*  @param rate the OutputRate
		*/
		virtual void setGNSOutputRate(OutputRate rate) = 0;

                /**
		*  Get the GSA output rate.
        *  	GPS DOP and active satellites.
		*  @return rate the OutputRate
		*/
		virtual OutputRate getGSAOutputRate() const = 0;

		/**
		*  Set the GSA output rate.
        *  GPS DOP and active satellites.
		*  @param rate the OutputRate
		*/
		virtual void setGSAOutputRate(OutputRate rate) = 0;
	};
}
#endif