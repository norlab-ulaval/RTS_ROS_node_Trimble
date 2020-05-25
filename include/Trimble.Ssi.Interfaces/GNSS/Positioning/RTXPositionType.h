#ifndef RTXPOSITIONTYPE_H_
#define RTXPOSITIONTYPE_H_

namespace SSI
{
	/**
	* Represents rtx position type of <see cref="IRTXPositionTypeObservation"/>.
	* The value of <see cref="IRTXPositionTypeObservation.RTXPositionType"/> will be one of these values.
	* <seealso cref="IRTXPositionTypeObservation"/>
	* <seealso cref="ISsiPositioning"/>
	*/
	enum RTXPositionType
	{
		PT_CenterPointFastInit = 1,
		PT_CenterPoint,
		PT_RangePoint,
		PT_FieldPoint,
		PT_ViewPoint
	};
}
#endif