#ifndef TURNTOSETTINGS_H_
#define TURNTOSETTINGS_H_

#include "ITurnToFeature.h"
#include "ITurnToParameter.h"

#include <vector>

namespace SSI
{
	/**
	* Represents the settings for a turn to operation via <see cref="ISsiServo.TurnTo(TurnToSettings)"/>.
	* <seealso cref="ISsiServo"/>
	*/
	class TurnToSettings
	{
	public:

		/**
		* Initializes a new instance of the <see cref="TurnToSettings"/> class.
		* @param parameter The turn to parameter.
		*/
		TurnToSettings(ITurnToParameter& parameter);

		/**
		* Initializes a new instance of the <see cref="TurnToSettings"/> class.
		* @param parameter The turn to parameter.
		* @param features The features.
		*/
		TurnToSettings(ITurnToParameter& parameter, std::vector<ITurnToFeature*> features);
		virtual ~TurnToSettings();

		/**
		* Gets the the turn to parameter.
		* @return The turn to parameter.
		*/
		virtual ITurnToParameter& getParameter() const;

		/**
		* Gets the turn to features.
		* @param An enumeration of assigned <see cref="ITurnToFeature"/> instances.
		*/
		std::vector<ITurnToFeature*> getFeatures() const;
	private:
		/**
		* Sets the turn to parameter.
		* @param parameter the turn to parameter.
		*/
		virtual void setParameter(ITurnToParameter& parameter);
		std::vector<ITurnToFeature*> _parameters;
		ITurnToParameter& _parameter;
	};
}
#endif