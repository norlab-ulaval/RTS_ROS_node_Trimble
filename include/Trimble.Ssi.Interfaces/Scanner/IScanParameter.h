#ifndef ISCANPARAMETER_H
#define ISCANPARAMETER_H
#include "IScanResolution.h"
#include "Utilities/Frame/IFrame.h"
#include "Points/PointFormatType.h"
#include <string>
#include <vector>
#include "IScanEstimate.h"

namespace SSI
{
	/**
	* Defines members for all scan parameters.
	*/
	class IScanParameter
	{
	public:
		virtual ~IScanParameter();
		/**
		* Gets the scan resolution.
		* @return
		* The scan resolution.
		*
		*/
		virtual IScanResolution* getResolution() = 0;

		/**
		* Sets the scan resolution.
		* @return
		* The scan resolution.
		*
		*/
		virtual void setResolution(IScanResolution* resolution) = 0;

		/**
		* Gets the frame.
		* @return
		* The frame.
		*
		*/
		virtual IFrame* getFrame() = 0;

		/**
		* Sets the frame.
		* @param frame The frame.
		*
		*/
		virtual void setFrame(IFrame* frame) = 0;

		/**
		* Gets the type of the point format.
		* @return
		* The type of the point format.
		*
		*/
		virtual PointFormatType getPointFormatType() = 0;

		/**
		* Sets the type of the point format.
		* @param pointFormatType
		* The type of the point format.
		*
		*/
		virtual void setPointFormatType(PointFormatType pointFormatType) = 0;

		/**
		* Gets the path to the scan file.
		* @return The path to the scan file.
		*/
		virtual std::string getScanFilePath() = 0;

		/**
		* Gets the path to the scan file.
		* @param  scanFilePath The path to the scan file.
		* @remark The path must contain directory and file name and file extension.
		*         If the ScanFilePath is null or empty no file will be generated.
		*/
		virtual void setScanFilePath(std::string scanFilePath) = 0;

		/**
		* Lists all scan resolution types.
		* @return A list of all available scan resolution types.
		*/
		virtual std::vector<ResolutionType> listAllScanResolutionTypes() = 0;

		/**
		* Creates an instance of a specific scan resolution type.
		* @param resolutionType Type of the scan resolution.
		* @returns An instance of @see IScanResolution with the requested type.
		*/
		virtual IScanResolution * createScanResolution(ResolutionType resolutionType) = 0;

		/**
		* Lists all frame types.
		* @returns A list of all available frame types.
		*/
		virtual std::vector<FrameType> listAllFrameTypes() = 0;

		/**
		* Creates an instance of scan frame with regards to instrument's field of scan.
		* @param scanFrameType Type of the scan frame.
		* @return An instance of @see IFrame with the requested type.
		*/
		virtual IFrame* createScanFrame(FrameType scanFrameType) = 0;

		/**
		* Lists all point format types.
		* @return A list of all available point format types.
		*/
		virtual std::vector<PointFormatType> listAllPointFormatTypes() = 0;

		/**
		* Use this method to get time estimation relative to parameters.
		* @returns Estimate object.
		*/
		virtual IScanEstimate *  estimateScan() = 0;


		/**
		* Gets the default scan resolution.
		* @return
		* The scan resolution.
		*
		*/
		virtual IScanResolution* getDefaultResolution() = 0;

		/**
		* Gets the default frame.
		* @return
		* The frame.
		*
		*/
		virtual IFrame* getDefaultFrame() = 0;
	};
}
#endif // ISCANPARAMETER_H
