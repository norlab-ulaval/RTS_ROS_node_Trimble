#ifndef INMEASERIALOUTPUTSETTINGS_H
#define INMEASERIALOUTPUTSETTINGS_H

#include "INmeaOutputSettings.h"

namespace SSI
{
	/**
	*  SerialOutputSettings
	*/
	class INmeaSerialOutputSettings : public INmeaOutputSettings
	{
	public:
		virtual ~INmeaSerialOutputSettings();

		/**
		* Serial port Parity
		*/
		enum Parity
		{
			None, // None
			Even, // Even
			Odd   // Odd
		};

		/**
		*  Gets the baudrate.
		* @return int the Baudrate
		*/
		virtual int getBaudrate() const = 0;

		/**
		*  Sets the baudrate.
		* @param baudrate the baudrate
		*/
		virtual void setBaudrate(int baudrate) = 0;

		/**
		*  Gets the parity.
		*  @return Parity current parity
		*/
		virtual Parity getParity() const = 0;

		/**
		*  Sets the parity.
		*/
		virtual void setParity(Parity parity) = 0;
	};
}
#endif