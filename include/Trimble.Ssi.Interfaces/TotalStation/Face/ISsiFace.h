#ifndef ISSIFACE_H_
#define ISSIFACE_H_

#include "ISsiInterface.h"
#include "InstrumentFace.h"
#include <vector>

namespace SSI
{
	/**
	* Access to the instruments face functionality.
	*/
	class ISsiFace : public ISsiInterface
	{
	public:
		virtual ~ISsiFace();

		/**
		* Get the supported faces
		* @return the supported faces
		*/
		virtual std::vector<InstrumentFace> listSupportedInstrumentFaces() const = 0;

		/**
		* is this face supported.
		* @param InstrumentFace to check
		* @return true if it is otherwise false
		*/
		virtual bool isInstrumentFaceSupported(InstrumentFace instrumentFace) const = 0;

		/**
		* Get the face.
		* @return the face
		*/
		virtual InstrumentFace getFace() const = 0;

		/**
		* Change the face.
		*/
		virtual void changeFace() = 0;
	};
}
#endif