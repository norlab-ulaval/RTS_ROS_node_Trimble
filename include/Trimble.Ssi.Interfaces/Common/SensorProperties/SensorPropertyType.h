#ifndef SENSORPROPERTYTYPE_H_
#define SENSORPROPERTYTYPE_H_

namespace SSI
{
	/**
	* Possible sensor property types
	*/
	enum SensorPropertyType
	{
		SPT_Firmware,				/** Firmware */
		SPT_Model,					/** Model */
		SPT_Name,					/** Name */
		SPT_SerialNumber,			/** Serial number */
		SPT_ReceiverId,				/** Receiver Id */
		SPT_NumberOfChannels,		/** Number Of channels */
		SPT_InstalledMemory,		/** Installed storage memory size*/
		SPT_FirmwareWarrantyDate,
		SPT_FirmwareUpdateRecommended
	};
}
#endif
