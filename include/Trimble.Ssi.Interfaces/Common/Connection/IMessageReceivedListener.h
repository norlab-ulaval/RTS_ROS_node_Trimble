#ifndef IMESSAGERECEIVEDLISTENER_H_
#define IMESSAGERECEIVEDLISTENER_H_

namespace Common
{
	/**
	* Listen for byte array received event.
	*/
	class IMessageReceivedListener
	{
	public:
		virtual ~IMessageReceivedListener();

		/**
		* Event that a new message was received occurred.
		* @param receivedMessage received message
		* @param length of the message
		*/
		virtual void onMessageReceived(const unsigned char* receivedMessage, unsigned int length) = 0;

		/**
		* Event that a new message was received occurred.
		* @param receivedMessage received message
		* @param length of the message buffer
		* @param length of the message
		*/
		void onMessageReceived(const unsigned char* receivedMessage, unsigned int bufferlength, unsigned int length);
	};
}
#endif
