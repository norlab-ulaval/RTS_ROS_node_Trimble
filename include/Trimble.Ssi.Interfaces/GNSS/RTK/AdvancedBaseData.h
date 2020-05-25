#ifndef ADVANCEDBASEDATA_H_
#define ADVANCEDBASEDATA_H_

#include <string>

namespace SSI
{
	/*
	* Represents survey controller base data.
	*/
	class AdvancedBaseData
	{
	public:
		/*
		* Initializes a new instance of the AdvancedBaseData class.
		* @param std::string
		* @param int
		*/
		AdvancedBaseData(std::string code, int antennaId);

		/*
		* Initializes a new instance of the AdvancedBaseData class.
		* @param AdvancedBaseData&
		*/
		AdvancedBaseData(const AdvancedBaseData& assignMe);

		/*
		* Gets the code.
		* @return std::string
		*/
		std::string getCode();

		/*
		* Gets the antenna identifier.
		* @return int
		*/
		int getAntennaId();

		AdvancedBaseData& operator=(const AdvancedBaseData& assignMe);
	private:
		std::string _code;
		int _antennaId;
	};
}
#endif