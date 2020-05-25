#ifndef ISSISTATUSLIGHT_H
#define ISSISTATUSLIGHT_H
#include "ISsiInterface.h"
#include "IStatusLightConfiguration.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access the status light of an instrument.
	*/
	class ISsiStatusLight : public ISsiInterface
	{
	public:
		virtual ~ISsiStatusLight();

		/**
		* Returns an enumeration of available <see cref="StatusLightType"/>.
		* @remarks Use <see cref="createStatusLightConfiguration(StatusLightType)"/> To create an <see cref="IStatusLightConfiguration"/> by it's type.
		* @return An enumeration of available <see cref="StatusLightType"/> objects.
		* @remarks Please be aware, that the underlying enumeration later may contain values, which are not known now.
		*/
		virtual std::vector<StatusLightType> listSupportedStatusLightTypes() const = 0;

		/**
		* Determines whether the specified status light is supported.
		* @param type The type.
		* @return bool
		*/
		virtual bool isSupported(StatusLightType type) const = 0;

		/**
		* Creates an <see cref="IStatusLightConfiguration"/> based on a <see cref="StatusLightType"/>.
		* @param type Type from which an <see cref="IStatusLightConfiguration"/> should be created.
		* @return <see cref="StatusLightType"/> corresponding to the passed <see cref="StatusLightType"/>.
		*/
		virtual IStatusLightConfiguration* createStatusLightConfiguration(StatusLightType type) const = 0;

		/**
		* Returns the current <see cref="IStatusLightConfiguration"/>.
		* @return The current <see cref="IStatusLightConfiguration"/>.
		*/
		virtual std::vector<IStatusLightConfiguration*> getStatusLightConfiguration() const = 0;

		/**
		* Set status light configuration.
		* @remarks Setting the target will never affect the streaming of idle angles or tilt values.
		* @remarks An ongoing tracking will be stopped, when a new target gets set.
		* @remarks Changing the current target while the instrument is measuring or searching will lead to a <see cref="SensorBusyException"/>.
		* @param statusLightConfiguration The status light configuration to be set.
		*/
		virtual void setStatusLightConfiguration(std::vector<IStatusLightConfiguration*>& statusLightConfiguration) = 0;
	};
}
#endif