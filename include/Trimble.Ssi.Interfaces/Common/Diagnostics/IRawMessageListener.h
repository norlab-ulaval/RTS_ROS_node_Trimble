#ifndef IRAWMESSAGELISTENER_H_
#define IRAWMESSAGELISTENER_H_


namespace SSI
{
	class RawMessageUpdate;


	/**
	* Listens for raw messages.
	*/
	class IRawMessageListener
	{
	public:
		virtual ~IRawMessageListener();

		/**
		* receives the event message when message arrived.
		*/
		virtual void onRawMessageUpdate(int type, unsigned char* data, unsigned dataSize) =0;
	};

	
}
#endif