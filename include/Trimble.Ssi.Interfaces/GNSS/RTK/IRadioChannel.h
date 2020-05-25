#ifndef IRADIOCHANNEL_H_
#define IRADIOCHANNEL_H_

namespace SSI
{
	/**
	* Represents radio channel information.
	*/
	class IRadioChannel
	{
	public:
		virtual ~IRadioChannel();

		/**
		* Gets the id.
		*
		* @return The id.
		*/
		virtual int getId ()=0;

		/**
		* Gets the frequency.
		*
		* @return The frequency.
		*/
		virtual double getFrequency ()=0;

		/**
		* Gets value indicating whether [in use].
		*
		* @return true if in use; otherwise, false
		*/
		virtual bool getInUse ()=0;

		/**
		* Sets a value indicating whether [in use].
		*
		* @param inUse set to true if in use; otherwise, false
		*/
		virtual void setInUse (bool inUse )=0;
	};
}
#endif