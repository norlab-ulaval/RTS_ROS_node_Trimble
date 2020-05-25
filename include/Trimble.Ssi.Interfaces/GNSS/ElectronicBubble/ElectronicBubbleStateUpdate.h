#ifndef ELECTRONICBUBBLESTATEUPDATE_H
#define ELECTRONICBUBBLESTATEUPDATE_H

#include "ElectronicBubbleState.h"

namespace SSI
{
	/**
	* Event data for electronic bubble state changes
	*/
	class ElectronicBubbleStateUpdate
	{
	public:
		/**
		* Initializes a new instance of the @see ElectronicBubbleStateUpdate class.
		* @param electronicBubbleState State of the electronic bubble.
		*/
		ElectronicBubbleStateUpdate(ElectronicBubbleState electronicBubbleState);
		ElectronicBubbleStateUpdate(const ElectronicBubbleStateUpdate &src);
		ElectronicBubbleStateUpdate& operator=(const ElectronicBubbleStateUpdate& assignMe);

		/**
		* Gets the state of the electronic bubble.
		* @return The state of the electronic bubble.
		*/
		ElectronicBubbleState getElectronicBubbleState() const;
	private:
		ElectronicBubbleState _electronicBubbleState;
	};
}
#endif