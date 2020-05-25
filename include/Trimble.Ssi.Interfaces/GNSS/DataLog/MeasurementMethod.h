#ifndef MeasurementMethod_H_
#define MeasurementMethod_H_

namespace SSI
{
	/**
	* Represents Antenna height measurement methods.
	*/
	enum MeasurementMethod
	{
		/**
		* Antenna Height is measured to the antenna phase center.
		*/
		MeasurementMethod_AntennaPhaseCenter,

		/**
		* Antenna Height is measured based on MeasMethod0 in Antenna.ini.
		*/
		MeasurementMethod_0,

		/**
		* Antenna Height is measured based on MeasMethod1 in Antenna.ini.
		*/
		MeasurementMethod_1,

		/**
		* Antenna Height is measured based on MeasMethod2 in Antenna.ini.
		*/
		MeasurementMethod_2,

		/**
		* Antenna Height is measured based on MeasMethod3 in Antenna.ini.
		*/
		MeasurementMethod_3,

		/**
		* Antenna Height is measured based on MeasMethod4 in Antenna.ini.
		*/
		MeasurementMethod_4,

		/**
		* Antenna Height is measured based on MeasMethod5 in Antenna.ini.
		*/
		MeasurementMethod_5,

		/**
		* Antenna Height is measured based on MeasMethod6 in Antenna.ini.
		*/
		MeasurementMethod_6,

		/**
		* Antenna Height is measured based on MeasMethod7 in Antenna.ini.
		*/
		MeasurementMethod_7,

		/**
		* Antenna Height is measured based on MeasMethod8 in Antenna.ini.
		*/
		MeasurementMethod_8,

		/**
		* Antenna Height is measured based on MeasMethod9 in Antenna.ini.
		*/
		MeasurementMethod_9
	};
}
#endif