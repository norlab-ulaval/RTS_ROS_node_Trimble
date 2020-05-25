#ifndef TRIMBLE_CONTRACTS_ISPATIALIMAGEPROPERTYTYPE_H
#define TRIMBLE_CONTRACTS_ISPATIALIMAGEPROPERTYTYPE_H

namespace Trimble_Contracts
{
    /// <summary>
    /// enum for SpatialImagePropertyType
    /// </summary>
    enum SpatialImagePropertyType
    {
        SpatialImagePropertyType_Unknown = -1,
        SpatialImagePropertyType_Intrinsic,		
        SpatialImagePropertyType_IntrinsicCropping,
        SpatialImagePropertyType_IntrinsicDistortion,
        SpatialImagePropertyType_ExtrinsicCameraRelativeToTelescope,
		SpatialImagePropertyType_ExtrinsicEdmRelativeToTelescope,
        SpatialImagePropertyType_ExtrinsicTelescopeRelativeToInstrument,
        SpatialImagePropertyType_Camera,
    };
}
#endif
