#ifndef CORRECTIONDATARECEIVEDUPDATE_H_
#define CORRECTIONDATARECEIVEDUPDATE_H_

namespace SSI
{
	/*
	*  Provides data for the ICorrectionDataReceivedListener call back.
	*/
	class CorrectionDataReceivedUpdate
	{
	public:

		/*
		* Initializes a new instance of the CorrectionDataReceivedUpdate class.
		* @param receivedBytes
		*/
		CorrectionDataReceivedUpdate(unsigned int receivedBytes);
		virtual ~CorrectionDataReceivedUpdate();

		/*
		* Gets the received bytes.
		* @return  received bytes
		*/
		unsigned int getReceivedBytes();
	private:
		unsigned int _receivedBytes;
	};
}
#endif