#ifndef IDATUMRTCMGRIDRESIDUALS_H
#define IDATUMRTCMGRIDRESIDUALS_H

#include <vector>

namespace SSI
{
	/**
	* Represents Datum RTCM Grid residuals.
	*/
	class IDatumRtcmGridResiduals
	{
	public:
		virtual ~IDatumRtcmGridResiduals();

		/**
		* Gets the message number.
		*
		* @return The message number.
		*/
		virtual int getMessageNumber() const = 0;

		/**
		* Gets the system ID number.
		*
		* @return The system ID number.
		*/
		virtual int getSystemIDNumber() const = 0;

		/**
		* Gets the horizontal shift indicator.
		*
		* @return The horizontal shift indicator.
		*/
		virtual int getHorizontalShiftIndicator() const = 0;

		/**
		* Gets the vertical shift indicator.
		*
		* @return The vertical shift indicator.
		*/
		virtual int getVerticalShiftIndicator() const = 0;

		/**
		* Gets the grid area LAT origin.
		*
		* @return The grid area LAT origin.
		*/
		virtual double getGridAreaLatOrigin() const = 0;

		/**
		* Gets the grid area long origin.
		*
		* @return The grid area long origin.
		*/
		virtual double getGridAreaLongOrigin() const = 0;

		/**
		* Gets the grid area LAT spacing.
		*
		* @return The grid area LAT spacing.
		*/
		virtual double getGridAreaLatSpacing() const = 0;

		/**
		* Gets the grid area long spacing.
		*
		* @return The grid area long spacing.
		*/
		virtual double getGridAreaLongSpacing() const = 0;

		/**
		* Gets the mean LAT offset.
		*
		* @return The mean LAT offset.
		*/
		virtual double getMeanLatOffset() const = 0;

		/**
		* Gets the mean long offset.
		*
		* @return The mean long offset.
		*/
		virtual double getMeanLongOffset() const = 0;

		/**
		* Gets the mean alt offset.
		*
		* @return The mean alt offset.
		*/
		virtual double getMeanAltOffset() const = 0;

		/**
		* Gets the LAT offsets.
		*
		* @return The LAT offsets.
		*/
		virtual std::vector<double> getLatOffsets() const = 0;

		/**
		* Gets the long offsets.
		*
		* @return The long offsets.
		*/
		virtual std::vector<double> getLongOffsets() const = 0;

		/**
		* Gets the alt offsets.
		*
		* @return The alt offsets.
		*/
		virtual std::vector<double> getAltOffsets() const = 0;

		/**
		* Gets the horizontal interpolation method.
		*
		* @return The horizontal interpolation method.
		*/
		virtual int getHorizontalInterpolationMethod() const = 0;

		/**
		* Gets the vertical interpolation method.
		*
		* @return The vertical interpolation method.
		*/
		virtual int getVerticalInterpolationMethod() const = 0;

		/**
		* Gets the horizontal grid quality indicator.
		*
		* @return The horizontal grid quality indicator.
		*/
		virtual int getHorizontalGridQualityIndicator() const = 0;

		/**
		* Gets the vertical grid quality indicator.
		*
		* @return The vertical grid quality indicator.
		*/
		virtual int getVerticalGridQualityIndicator() const = 0;

		/**
		* Gets the modified julian date.
		*
		* @return The modified julian date.
		*/
		virtual int getModifiedJulianDate() const = 0;
	};
}
#endif