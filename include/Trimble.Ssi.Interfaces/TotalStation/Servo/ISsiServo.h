#ifndef ISSISERVO_H_
#define ISSISERVO_H_

#include "ISsiInterface.h"
#include "TurnToParameterType.h"
#include "ITurnToParameter.h"
#include "TurnToState.h"
#include "TurnToFeatureType.h"
#include "ITurnToFeature.h"
#include "TurnToSettings.h"
#include "ITurnToStateChangedListener.h"

#include <vector>

namespace SSI
{
	/**
	* Provides members to access the servo functions of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	*/
	class ISsiServo : public ISsiInterface
	{
	public:
		virtual ~ISsiServo();

		/**
		* register a turn to state changed listener.
		* @param ITurnToStateChangedListener the listener
		*/
		virtual void addTurnToStateChangedListener(ITurnToStateChangedListener& listener) = 0;

		/**
		* unsubscribe a turn to state changed listener.
		* @param ITurnToStateChangedListener the listener
		*/
		virtual void removeTurnToStateChangedListener(ITurnToStateChangedListener& listener) = 0;

		/**
		* Gets the state of the idle angle.
		* @return The state of the idle angle.
		*/
		virtual TurnToState getTurnToState() const = 0;

		/**
		* Returns all available turn to parameter types.
		* @return all available turn to parameter types
		*/
		virtual std::vector<TurnToParameterType> listSupportedTurnToParameterTypes() const = 0;

		/**
		* Is turn to parameter type supported.
		* @param TurnToParameterType to check
		* @return true if it is otherwise false
		*/
		virtual bool isTurnToParameterSupported(TurnToParameterType turnToParameterType) const = 0;

		/**
		* Returns an enumeration of available <see cref="TurnToFeatureType"/> values.
		* Use <see cref="CreateTurnToFeature"/> To create an <see cref="ITurnToFeature"/> by it's type.
		* Please be aware, that the underlying enumeration later may contain values, which are not known now.
		* @return An enumeration of available <see cref="TurnToFeatureType"/> objects.
		*/
		virtual std::vector<TurnToFeatureType> listSupportedTurnToFeatureTypes(TurnToParameterType turnToParameterType) const = 0;

		/**
		* Determines whether the specified turn automatic parameter type is supported.
		* @param turnToParameterType Type of the turn automatic parameter.
		* @param turnToFeatureType Type of the turn automatic feature.
		* @return true if it is supported, otherwise false.
		*/
		virtual bool isTurnToFeatureSupported(TurnToParameterType turnToParameterType, TurnToFeatureType turnToFeatureType) const = 0;

		/**
		* Creates an ITurnToParameter based on a TurnToParameterType for use with TurnTo.
		* @param TurnToParameterType turn to parameter type
		* @return an instance of turn to parameters
		*/
		virtual ITurnToParameter* createTurnToParameter(TurnToParameterType turnToParameterType) const = 0;

		/**
		* Creates an <see cref="ITurnToFeature"/> based on a <see cref="TurnToFeatureType"/> for use with <see cref="TurnToSettings"/>.
		* @param turnToFeatureType Type from which an <see cref="ITurnToFeature"/> should be created.
		* @return <see cref="ITurnToFeature"/> corresponding to the passed <see cref="TurnToFeatureType"/>.
		*/
		virtual ITurnToFeature* createTurnToFeature(TurnToFeatureType turnToFeatureType) const = 0;

		/**
		* Turns the sensor to a specific position defined by the given turn to parameters.
		* Use CreateTurnToParameter to create a parameter for this method.
		* @param ITurnToParameter the turn to parameters
		*/
		virtual void turnTo(ITurnToParameter& parameter) = 0;

		/**
		* Turns the sensor to a specific position defined by the given <paramref name="turnToSettings"/>.
		* Use <see cref="CreateTurnToParameter"/> to create a parameter for this method.
		* @param turnToSettings The <see cref="TurnToSettings"/>, defining the parameters of the turn to action.
		*/
		virtual void turnTo(TurnToSettings& turnToSettings) = 0;

		/**
		* Cancels an ongoing turn to operation.
		*/
		virtual void cancelTurnTo() = 0;
	};
}
#endif