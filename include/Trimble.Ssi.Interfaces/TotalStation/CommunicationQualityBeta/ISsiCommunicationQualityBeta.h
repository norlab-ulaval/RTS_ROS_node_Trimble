#ifndef ISSICOMMUNICATIONQUALITYBETA_H_
#define ISSICOMMUNICATIONQUALITYBETA_H_

#include "ISsiInterface.h"
#include "ILinkQualityListener.h"

namespace SSI
{
	/**
	* Provides members to access the reference circle settings of an instrument.
	* For a brief description of features and usage of various <see cref="ISsiInterface"/> see [Guides: Interfaces](@ref Guides_Interfaces).
	*/
	class ISsiCommunicationQualityBeta : public ISsiInterface
	{
	public:
		virtual ~ISsiCommunicationQualityBeta();

		/**
		* Checks the CommunicationQuality of the instrument.
		* @param timeout in sec value
		*/
		virtual void checkCommunicationQuality(double timeout) = 0;

		/**
		* register a listener for listening.
		* @param ILinkQualityListener to listen
		*/
		virtual void addLinkQualityListener(ILinkQualityListener& listener) = 0;

		/**
		* unsubscribe a listener from listening.
		* @param ILinkQualityListener to listen
		*/
		virtual void removeLinkQualityListener(ILinkQualityListener& listener) = 0;
	};
}
#endif