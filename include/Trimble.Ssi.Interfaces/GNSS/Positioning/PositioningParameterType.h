#ifndef POSITIONINGPARAMETERTYPE_H_
#define POSITIONINGPARAMETERTYPE_H_

namespace SSI
{
	/**
	* Represents positioning parameter type.
	* To get an enumeration of supported <see cref="PositioningParameterType"/> values, use <see cref="ISsiPositioning.ListSupportedPositioningParameterTypes"/>.
	* Use <see cref="ISsiPositioning.CreatePositioningParameter"/> to create an <see cref="IPositioningParameter"/>, which can be used to set the positioning parameter of the GNSS Receiver
	* <seealso cref="ISsiPositioning"/>
	*/
	enum PositioningParameterType
	{
		PPT_MotionState, /**< Parameter type is motion state. */
		PPT_PositionRate, /**< Parameter type is positioning rate. */
		PPT_AntennaHeight, /**< Parameter type is antenna height. */
	};
}
#endif