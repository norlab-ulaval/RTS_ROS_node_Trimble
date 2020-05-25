#ifndef ISSIRTXQUICKSTART_H_
#define ISSIRTXQUICKSTART_H_

#include "RTXInitializationState.h"
#include "IRTXInitializationStateListener.h"
#include "ISsiInterface.h"
#include "Coordinates.h"

namespace SSI
{
	class ISsiRTXQuickStart : public ISsiInterface
	{
	public:
		virtual ~ISsiRTXQuickStart();

		/*
		* register a listener for RTX initialization state listener.
		* @param IRTXInitializationStateListener to listen.
		*/
		virtual void addRTXInitializationStateListener(IRTXInitializationStateListener& listener) = 0;

		/*
		* register a listener for RTX initialization state listener.
		* @param IRTXInitializationStateListener to listen.
		*/
		virtual void removeRTXInitializationStateListener(IRTXInitializationStateListener& listener) = 0;

		/**
		* Gets the current state of the rtx position initialization.
		* @return The current state of the rtx position initialization.
		*/
		virtual RTXInitializationState getCurrentState() = 0;

		/**
		* Starts the initialization of the RTX position.
		*/
		virtual void initRTXReferencePosition(Coordinates coordinates) = 0;

		/**
		* Completes the initialization of the RTX position.
		*/
		virtual void completeInitialization() = 0;

		/**
		* Cancel the initialization of the RTX position.
		*/
		virtual void cancelInitRTXReferencePosition() = 0;
	};
}
#endif