#ifndef IRADIOCONFIGURATIONOUTPUTPOWER_H_
#define IRADIOCONFIGURATIONOUTPUTPOWER_H_

#include "IRadioConfigurationGnss.h"
#include <vector>

namespace SSI
{
	/**
	*  The radio parameter for describing the output power spacing
	*/
	class IRadioConfigurationOutputPower : public virtual IRadioConfigurationGnss
	{
	public:
		virtual ~IRadioConfigurationOutputPower();

		/**
		* Returns an enumeration of available <see cref="outputPower"/>.
		* Please be aware, that the underlying enumeration later may contain values, which are not known now.
		* @return An enumeration of available <see cref="outputPower"/> objects.
		*/
		virtual std::vector<double> listSupportedOutputPowerModes() const = 0;

		/**
		* Is outputPower supported.
		* @param outputPower to check
		* @return true if it is otherwise false
		*/
		virtual bool isOutputPowerSupported(double outputPower) const = 0;

		/**
		* get the outputPower.
		* @return the outputPower
		*/
		virtual double getOutputPower() const = 0;

		/**
		* sets the outputPower.
		*/
		virtual void setOutputPower(double outputPower) = 0;
	};
}
#endif