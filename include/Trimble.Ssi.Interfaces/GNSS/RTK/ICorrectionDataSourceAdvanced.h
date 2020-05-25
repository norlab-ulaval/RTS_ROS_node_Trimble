#ifndef ICORRECTIONDATASOURCEADVANCED_H_
#define ICORRECTIONDATASOURCEADVANCED_H_

#include "ICorrectionDataSource.h"
#include "CorrectionDataFormat.h"
#include <vector>

namespace SSI
{
	/*
	* Represents an ICorrectionDataSource which has a CorrectionDataFormat
	*/
	class ICorrectionDataSourceAdvanced : public virtual ICorrectionDataSource
	{
	public:
		virtual ~ICorrectionDataSourceAdvanced();

		/*
		* Lists the supported correction data formats.
		* @return std::vector<CorrectionDataFormat>
		*/
		virtual const std::vector<CorrectionDataFormat> listSupportedCorrectionDataFormats()  const =0;

		/*
		* Gets the format of the correction data.
		* @return CorrectionDataFormat
		*/
		virtual CorrectionDataFormat getDataFormat() const =0;

		/*
		* Sets the format of the correction data.
		* @param CorrectionDataFormat
		*/
		virtual void setDataFormat(CorrectionDataFormat correctionDataFormat)=0;
	};
}
#endif