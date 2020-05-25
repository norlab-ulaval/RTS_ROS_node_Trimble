#ifndef POSITIONINGSETTINGS_H_
#define POSITIONINGSETTINGS_H_

#include "IPositioningParameter.h"
#include <vector>

namespace SSI
{
	/*
	* Represents positioning settings.
	*/
	class PositioningSettings
	{
	public:
		/*
		* Initializes a new instance of the PositioningSettings class.
		*/
		PositioningSettings();
		~PositioningSettings();

		/*
		* Gets the parameters.
		* @return std::vector<IPositioningParameter>
		*/
		const std::vector<IPositioningParameter*>& getParameters();

		/*Adds the specified positioning parameter.
		* @param IPositioningParameter
		*/
		void add(IPositioningParameter& positioningParameter);
	private:
		std::vector<IPositioningParameter*> _list;
	};
}
#endif