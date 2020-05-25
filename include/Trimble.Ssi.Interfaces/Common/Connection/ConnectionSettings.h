#ifndef CONNECTIONSETTINGS_H_
#define CONNECTIONSETTINGS_H_

#include "ConnectionType.h"
#include "ConnectionParameterType.h"
#include "IConnectionParameter.h"

#include <vector>

namespace SSI
{
	/**
	* Holds the connection settings.
	* Use ISensor::Connect together with a ConnectionSettings instance to connect to a sensor.
	* @see ConnectionType
	* @see ISensor
	*/
	class ConnectionSettings
	{
	public:
		/**
		* Initializes a new instance.
		* A connection group can consist of just a single connection type.
		* @param connectionType the connection type
		*/
		ConnectionSettings(ConnectionType connectionType);

		/**
		* Initializes a new instance.
		* A connection group consists of a non-null connection type and an variable
		/// set of additional parameters.
		* @param connectionType the connection type
		* @param parameter additional Connection parameters
		*/
		ConnectionSettings(ConnectionType connectionType, std::vector<IConnectionParameter*>& parameter);

		/**
		* Uninitializes a instance.
		*/
		virtual ~ConnectionSettings();

		/**
		* Gets the connection type.
		* @return the connection type
		*/
		ConnectionType getConnectionType() const;

		/**
		* Use this method to query a specific connection parameter.
		* @param connectionParameterType to be queried
		* @return the requested Parameter
		*/
		IConnectionParameter& getConnectionParameter(ConnectionParameterType connectionParameterType) const;

        /**
        * Use this method to query a specific connection parameter.
        * @param connectionParameterType to be queried
        * @return if the requested Parameter exists
        */
        bool hasConnectionParameter(ConnectionParameterType connectionParameterType) const;

		/**
		* Get the list of connection parameters.
		*@return the available connection parameters
		*/
		std::vector<IConnectionParameter*> getConnectionParameters() const;
		ConnectionSettings& operator=(const ConnectionSettings&);
	private:
		ConnectionSettings();
		ConnectionSettings(const ConnectionSettings& copyMe);
		ConnectionType _connectionType; /**< the connection type */
		std::vector<IConnectionParameter*> _connectionParameters; /** the connection parameters */
	};
}
#endif
