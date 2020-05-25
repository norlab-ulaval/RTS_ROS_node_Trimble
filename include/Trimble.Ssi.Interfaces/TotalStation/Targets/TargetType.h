#ifndef TARGETTYPE_H_
#define TARGETTYPE_H_

namespace SSI
{
	/**
	* Represents a type of a target.
	* To get an enumeration of supported TargetType values, use ISsiTargets::ListSupportedTargetTypes.
	* Use ISsiTargets::CreateTarget to create a specific target based on the TargetType.
	* @see ISsiTargets
	*/
	enum TargetType
	{
		TT_DirectReflex,					/**< A type of targets which reflect at various surfaces e.g. walls. It comes with basic laser pointer capabilities. */
		TT_DirectReflexHighPowerLaser,		/**< A type of targets which reflect at various surfaces e.g. walls. An instrument supporting this type of a target comes with the eccentrically 3R laser pointer. */
		TT_DirectReflexAdvanced,			/**< A type of targets which reflect at various surfaces e.g. walls. An instrument supporting this type comes with capabilities for using weak signals and limiting the expected slope distance. */
		TT_Prism,							/**< A type of targets representing basic physical prism. */
		TT_PrismId,							/**< */
		TT_PrismAdvanced,					/**< A type of targets representing physical prisms which can be locked. */
		TT_Trimble360,						/**< A type of targets representing responsive %Trimble 360° prisms. */
		TT_Trimble360Passive,				/**< A type of targets representing passive %Trimble 360° prisms. */
		TT_TrimbleMultiTrack,				/**< A type of targets representing responsive %Trimble MultiTrack prisms. */
		TT_TrimbleMultiTrackPassive,		/**< A type of targets representing passive %Trimble MultiTrack prisms. */
		TT_TrimbleMultiTrackMachineControl, /**< A type of targets representing %Trimble MultiTrack machine control prisms. */
		TT_PrismFinelock,					/**< A type of targets representing physical prisms that can be used for measuring with Finelock. */
		TT_PrismFinelockLongRange,			/**< A type of targets representing physical prisms that can be used for measurement with Finelock at ranges up to 2500 meters. */
		TT_PrismLongRange,					/**< A type of targets representing physical prisms that can be used for measurement at ranges up to 5500 meters. */
		TT_GreenHighPowerLaser,				/**< A type of targets representing the green high power laser. */
		TT_TrimbleActiveTrack360,			/**<  A type of targets representing %Trimble Active Track 360 prisms.. */
		TT_PrismWithSize,					/**< */
		TT_ReflectiveFoilSticker,			/**< */
		TT_CateyeSticker,					/**< */
		TT_Prism360Degree,					/**< */
		TT_Cateye360Degree					/**< */
	};
}
#endif