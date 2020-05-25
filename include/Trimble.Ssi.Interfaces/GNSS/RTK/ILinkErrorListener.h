#ifndef ILINKERRORLISTENER_H_
#define ILINKERRORLISTENER_H_

namespace SSI
{
	/**
	* Listens for Error in RTKSurvey Link.
	*/
	class ILinkErrorListener
	{
	public:
		virtual ~ILinkErrorListener();

		/**
		* Triggered when connection is lost.
		*/
		virtual void onConnectionLost()=0;
	};
}
#endif