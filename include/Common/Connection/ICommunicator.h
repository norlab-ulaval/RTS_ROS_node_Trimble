#ifndef ICOMMUNICATOR_H_
#define ICOMMUNICATOR_H_

#include "IMessageReceivedListener.h"
#include "IConnectionStateChangedListener.h"
#include "ConnectionState.h"

namespace Common
{
	/**
	*  interface for communication over a connection.
	*/
	class ICommunicator
	{
	public:
		virtual ~ICommunicator();

		/**
		* connect to something.
		* @return <c>true</c> if connected; otherwise <c>false</c>
		*/
		virtual bool connect() = 0;

		/**
		* cancel a not yet established connection.
		* @return <c>true</c> if canceled; otherwise <c>false</c>
		*/
		virtual bool cancelConnect() = 0;

		/**
		* disconnect to something.
		* @return <c>true</c> if disconnected; otherwise <c>false</c>
		*/
		virtual bool disconnect() = 0;

		/**
		* Register a listener to get informed when events happen.
		* @param listener the listener to register
		*/
		virtual void addConnectionStateChangedListener(IConnectionStateChangedListener& listener) = 0;

		/**
		* Unregister a listener.
		* @param listener the listener to unsubscribe
		*/
		virtual void removeConnectionStateChangedListener(IConnectionStateChangedListener& listener) = 0;

		/**
		* Get the state of the connection.
		* @return the connection state
		*/
		virtual ConnectionState getConnectionState() const = 0;

		/**
		* send a message over the established connection.
		* @param message to push
		* @param length number of bytes to push
		*/
		virtual void pushMessage(const unsigned char* message, unsigned int length) = 0;

		/**
		* set a listener.
		* @param IByteArrayReceivedListener listener to set
		*/
		virtual void setMessageReceivedListener(IMessageReceivedListener& listener) = 0;

		/**
		* Event that a new message was received occurred.
		* @param receivedMessage received message
		* @param length of the message
		*/
		virtual void onNewMessageReceived(const unsigned char* receivedMessage, unsigned int length) = 0;
	};
}
#endif
