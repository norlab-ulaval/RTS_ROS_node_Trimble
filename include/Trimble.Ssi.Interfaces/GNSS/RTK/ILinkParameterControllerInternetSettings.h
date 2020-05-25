#ifndef ILINKPARAMETERCONTROLLERINTERNETSETTINGS_H_
#define ILINKPARAMETERCONTROLLERINTERNETSETTINGS_H_

#include "ILinkParameter.h"
#include "Connection/ITCPCommunicator.h"
#include "ILinkErrorListener.h"

namespace SSI
{
	/*
	* Represents Link parameter Controller internet settings.
	*/
	class ILinkParameterControllerInternetSettings: public ILinkParameter
	{
	public:
		virtual ~ILinkParameterControllerInternetSettings();

		/**
		* register a listener for listening link connection error.
		* @param ILinkErrorListener to listen
		*/
		virtual void addLinkErrorListener(ILinkErrorListener& listener) = 0;

		/**
		* register a listener for listening link connection error.
		* @param ILinkErrorListener to listen
		*/
		virtual void removeLinkErrorListener(ILinkErrorListener& listener) = 0;

		/*
		* Sets the Communicator.
		* @param communicator Communicator instance
		*/
		virtual void setCommunicator(ITCPCommunicator* communicator) = 0;

		/*
		* Gets the Communicator.
		* @return Communicator instance
		*/
		virtual ITCPCommunicator* getCommunicator() const = 0;

		/*
		* Reconnect Link layer after a lose in connection.
		*/
		virtual void reconnectLink() = 0;
	};
}
#endif