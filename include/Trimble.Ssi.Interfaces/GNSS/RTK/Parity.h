#ifndef PARITY_H_
#define PARITY_H_

namespace SSI
{
	/**
	* Represents GPS Radio communication Parity
	*/
	enum Parity
	{
		/**
		* GPS Parity is none
		*/
		Parity_None,

		/**
		* GPS Parity is odd
		*/
		Parity_Odd,
	
		/**
		* GPS Parity is even
		*/
		Parity_Even
	};
}
#endif