#ifndef ICORRECTIONDATASOURCE_H
#define ICORRECTIONDATASOURCE_H

#include "CorrectionDataSourceType.h"

namespace SSI
{
	/*
	* Represents correction data source.
	*/
	class ICorrectionDataSource
	{
	public:
		virtual ~ICorrectionDataSource();

		/*
		* Gets the type.
		* @return CorrectionDataSourceType
		*/
		virtual CorrectionDataSourceType getType() const=0 ;

		/**
		* clone
		* @return reference of an object allocated in heap
		*/
		//virtual ICorrectionDataSource* clone() const=0;
	};
}
#endif