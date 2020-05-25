#ifndef ICAMERAIMAGEPROPERTYCAMERAID_H
#define ICAMERAIMAGEPROPERTYCAMERAID_H
#include "IImagingProperty.h"

namespace SSI
{
	/**
	 * Represents an image property carrying information about the camera identifier.
	 */
	class ICameraImagePropertyCameraId : public IImagingProperty
	{
	public:

		virtual ~ICameraImagePropertyCameraId();

		/**
		 * Gets the identifier.
		 * @return the identifier
		 */
		virtual int getID() = 0;
	};
	
}
#endif // ICAMERAIMAGEPROPERTYCAMERAID_H
