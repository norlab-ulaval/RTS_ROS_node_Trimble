#ifndef LICENSEEXCEPTION_H
#define LICENSEEXCEPTION_H
#include "SsiException.h"

namespace  SSI 
{
	//Used by iOS Client
	class LicenseException : public SsiException
	{
	public:
		LicenseException(bool validLicenseFile,bool validSerialNumber,bool validSignature);
		bool isLicenseFileValid();
		bool isSerialNumberValid();
		bool isSignatureValid();
	private:
		bool _validLicenseFile;
		bool _validSerialNumber;
		bool _validSignature;
	};
}
#endif // LICENSEEXCEPTION_H
