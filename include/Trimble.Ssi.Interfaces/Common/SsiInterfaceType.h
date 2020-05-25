#ifndef SSIINTERFACETYPE_H_
#define SSIINTERFACETYPE_H_

namespace SSI
{
	/**
	* Available interface types.
	*/
	enum SsiInterfaceType
	{
		// Read instrument parameter
		IT_SsiSensorProperties, /**< */
		IT_SsiServiceInfo, /**< */
		IT_SsiInstrumentAccuracies, /**< */
		IT_SsiPpmCorrectionParameter, /**< */
		IT_SsiRadioConfigurationTS, /**< */
		IT_SsiRadioConfigurationGnss, /**< */
		IT_SsiStartupConfiguration, /**< */
		IT_SsiAntenna,/**< */
		IT_SsiCommunicationQualityBeta,
		IT_SsiDisplay,
		IT_SsiFirmwareUpdate,
		IT_SsiAuthentication,

		// Read values
		IT_SsiPower, /**< */
		IT_SsiPressure, /**< */
		IT_SsiTemperature, /**< */

		//OptionCode
		IT_SsiOptionCode,

		//Satellites
		IT_SsiSatellites,/**< */

		// Tilt and compensator
		IT_SsiIdleAngles, /**< */
		IT_SsiTilt, /**< */
		IT_SsiTiltCompensator, /**< */

		// Adjustment
		IT_SsiCalibration, /**< */
		IT_SsiElectronicBubble, /**< */
		IT_SsiCorrectionValues, /**< */

		// Independent settings
		IT_SsiStatusLight,
		IT_SsiTrackLight, /**< */
		IT_SsiReticle, /**< */
		//IT_SsiReferenceCircle,
		IT_SsiHorizontalAngleAdjustment, /**< */
		IT_SsiLaserPlummet, /**< */

		// Servo
		IT_SsiServo, /**< */
		IT_SsiServoFocus,
		IT_SsiFace, /**< */
		IT_SsiJoystick, /**< */

		// Target with depending interface
		IT_SsiTargets, /**< */

		//TargetAiming
		IT_SsiTargetAiming, /**< */

		// Search
		IT_SsiSearch, /**< */
		IT_SsiMultiTargetSearch, /**< */
		// Measure
		IT_SsiMeasurement, /**< */
		IT_SsiTracking, /**< */

		//GNSS Positioning
		IT_SsiRTKSurvey,/**< */
		IT_SsiRTKInitialization,
		IT_SsiRTXQuickStart, /**< */
		IT_SsiDataLogSurvey, /**< */
		IT_SsiReceiverFiles, /**< */

		IT_SsiPositioning, /**< */
		IT_SsiTiltedMeasurement, /**< */

		// Scanner
		IT_SsiScan,

		// Vision
		IT_SsiVision, /**< */

		//Nmea
		IT_SsiNmeaOutput, /**< */

		//Subscriptions
		IT_SsiSubscriptions,

		//SsiSessionInfo
		IT_SsiSessionInfo,

		//SsiDiagnostics
		IT_SsiDiagnostics
	};
}
#endif
