#ifndef IRESOLUTIONPRESET_H
#define IRESOLUTIONPRESET_H
#include <vector>
#include "PresetType.h"
#include "IScanResolution.h"

namespace SSI
{
	/**
	 * A preset of a scan resolution
	 * @see Trimble.Ssi.Interfaces.Scanner.IScanResolution
	 */
	class IResolutionPreset : public virtual  IScanResolution
	{
	public:
		virtual ~IResolutionPreset();

		/**
		* Gets the list of Supported presets.
		* @return
		* The list of all Supported presets.
		*
		*/
		virtual std::vector<PresetType> listSupportedPresetTypes() = 0;

		/**
		* Gets the type of the preset
		*/
		virtual PresetType getPresetType() = 0;

		/**
		* Sets the type of the preset
		*/
		virtual void setPresetType(PresetType presetType) = 0;
	};
}

#endif // IRESOLUTIONPRESET_H
