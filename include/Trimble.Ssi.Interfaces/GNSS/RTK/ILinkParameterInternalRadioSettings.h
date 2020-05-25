#ifndef ILINKPARAMETERINTERNALRADIOSETTINGS_H_
#define ILINKPARAMETERINTERNALRADIOSETTINGS_H_

#include "ILinkParameterRadioSettings.h"
#include "IRadioChannel.h"
#include <vector>

namespace SSI
{
	/**
	* Represents link parameter internal radio settings.
	*
	* @see ISsiRTKSurvey
	*/
	class ILinkParameterInternalRadioSettings:public ILinkParameterRadioSettings
	{
	public:
		~ILinkParameterInternalRadioSettings();
	
		/**
		* Gets the channel id.
		* @return The channel id.
		*/
		virtual int getChannelID() const=0;

		/**
		* Gets or sets the channel id.
		*
		* @param channeldID The channel id.
		*/
		virtual void setChannelID(int channelID)=0;

		/**
		* Scans for channels.
		*
		* @returns Enumeration of channels
		*/
		virtual std::vector<IRadioChannel*> scanForChannels()=0;
	};
}
#endif