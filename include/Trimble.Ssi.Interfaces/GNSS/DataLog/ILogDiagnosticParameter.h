#ifndef ILOGDIAGNOSTICPARAMETER_H_
#define ILOGDIAGNOSTICPARAMETER_H_

#include "ILogParameter.h"

namespace SSI
{
    /**
     * Provides access to setter and getter for diagnostic parameter.
     */
    class ILogDiagnosticParameter : public ILogParameter
    {
    public:
        virtual ~ILogDiagnosticParameter();

        /**
         * Gets the option for logging of internal diagnostic messages.
         *
         * @returns The option.
         */
        virtual bool getDiagnostics() const = 0;

        /**
         * Sets the option for logging of internal diagnostic messages.
         *
         * @param on The option.
         */
        virtual void setDiagnostics(bool on) = 0;

        /**
         * Gets the option for logging of received correction messages.
         *
         * @returns corrections.
         */
        virtual bool getCorrections() const = 0;

        /**
         * Sets the option for logging of received correction messages.
         *
         * @param corrections.
         */
        virtual void setCorrections(bool on) = 0;

		 /**
         * Sets the interval for logging positions for diagnostics.
         *
         * @param positionInterval.
         */
        virtual void setPositionInterval(double positionInterval) = 0;

		 /**
         * Gets the interval for logging positions for diagnostics.
         *
         * @returns positionInterval.
         */
		virtual double getPositionInterval() const = 0;
    };
}
#endif