#ifndef RESOLUTIONTYPE_H
#define RESOLUTIONTYPE_H
/**
* Represents a scan resolution type of a scan resolution.
* @remarks 
*   To get an enumeration of supported @see ResolutionType values, use @see IScanParameter.ListAllScanResolutionTypes.
* @see IScanParameter
*/
enum ResolutionType
{
	/**
	* Angular resolution type for defining vertical and horizontal angles between scanned points.
	*/
	ResolutionType_Angular,

	/**
	* Spatial resolution type for defining a minimal distance between scanned points.
	*/
	ResolutionType_Spatial,

	/**
	* List of angular preset resolutions.
	*/
	ResolutionType_PresetAngles,

	/**
	* List of spatial preset resolutions.
	*/
	ResolutionType_PresetSpatials,

	/**
	* The time based resolution type.
	*/
	ResolutionType_TimeBased,

    /**
    * The speed resolution type.
    */
    ResolutionType_Speed,

    /**
    * List of speed preset resolutions.
    */
    ResolutionType_PresetSpeed,
};
#endif // RESOLUTIONTYPE_H
