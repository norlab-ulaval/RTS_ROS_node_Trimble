#ifndef IVCVOBSERVATION_H
#define IVCVOBSERVATION_H

#include "IGNSSObservation.h"

namespace SSI
{
	/*
	*  Represents a variance-covariance matrix observation.
	*/
	class IVCVObservation: public IGNSSObservation
	{
	public:
		virtual ~IVCVObservation(void);

		/**
		* Gets the VCVxx.
		* @return The VCVxx.
		*/
		virtual double getVCVxx() =0;

		/**
		* Gets the VCVxy.
		* @return The VCVxy.
		*/
		virtual double getVCVxy()=0;

		/**
		* Gets the VCVxz.
		* @return The VCVxz.
		*/
		virtual double getVCVxz()=0;

		/**
		* Gets the VCVyy.
		* @return The VCVyy.
		*/
		virtual double getVCVyy()=0;

		/**
		* Gets the VCVyz.
		* @return The VCVyz.
		*/
		virtual double getVCVyz()=0;

		/**
		* Gets the VCVzz.
		* @return The VCVzz.
		*/
		virtual double getVCVzz()=0;

		/**
		* Gets the UnitVariance.
		* @return The UnitVariance.
		*/
		virtual double getUnitVariance()=0;

	};
}
#endif