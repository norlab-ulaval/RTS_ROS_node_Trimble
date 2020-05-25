#ifndef ISSITARGETAIMING_H_
#define ISSITARGETAIMING_H_

#include "ISsiInterface.h"
#include "ITargetAimingParameter.h"
#include <vector>

namespace SSI
{
	/**
	* Provides members to access TargetAiming functions of an instrument.
	* For a brief description of features and usage of various ISsiInterface see [Guides: Interfaces](@ref Guides_Interfaces)
	* @see ISsitargetAiming
	*/
	class ISsiTargetAiming : public ISsiInterface
	{
	public:
		virtual ~ISsiTargetAiming();

		/**
		* Returns all available TargetAimingParameter parameter types.
		* @return all available TargetAimingParameter parameter types
		*/
		virtual std::vector<TargetAimingParameterType> listSupportedParameterTypes() const = 0;

		/**
		* Is TargetAimingParameterType supported.
		* @param TargetAimingParameterType to check
		* @return true if it is otherwise false
		*/
		virtual bool isSupported(TargetAimingParameterType targetAimingParameterType) const = 0;

		/**
		* Creates an ITargetAimingParameter based on a TargetAimingParameterType.
		* @param TargetAimingParameterType to parameter type
		* @return an instance of TargetAimingParameterType parameters
		*/
		virtual ITargetAimingParameter& getTargetAimingParameter(TargetAimingParameterType targetAimingParameterType) const = 0;

		/**
		* Sets an ITargetAimingParameter based on a TargetAimingParameter.
		* @param targetAimingParameter to the parameter 
		*/
		virtual void setTargetAimingParameter(ITargetAimingParameter& targetAimingParameter) = 0;
	}; 
}
#endif 
