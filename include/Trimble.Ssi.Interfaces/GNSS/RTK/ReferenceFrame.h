#ifndef ITRF2008EPOCH_H
#define ITRF2008EPOCH_H

namespace SSI
{
	/**
	* Represents the supported reference frames (datums)
	*
	* @see ICorrectionDataSourceRtxSettings
	*/
	enum ReferenceFrame
	{
		/**
		* Reference frame is not used
		* No transformation will be transformed
		* @remarks  Raw RTX positions for example
		*/
		ReferenceFrame_Off,

		/**
		* Reference frame is undefined.
		* @remarks Used for auto selection
		*/
		ReferenceFrame_Unknown,

		/**
		* International Terrestrial Reference Frame 1988  (epoch 1988)
		*/
		ReferenceFrame_ITRF1988,

		/**
		* International Terrestrial Reference Frame 1989 (epoch 1988)
		*/
		ReferenceFrame_ITRF1989,

		/**
		* International Terrestrial Reference Frame 1990 (epoch 1988)
		*/
		ReferenceFrame_ITRF1990,

		/**
		* International Terrestrial Reference Frame 1991 (epoch 1988)
		*/
		ReferenceFrame_ITRF1991,

		/**
		* International Terrestrial Reference Frame 1992 (epoch 1988)
		*/
		ReferenceFrame_ITRF1992,

		/**
		* International Terrestrial Reference Frame 1993 (epoch 1993)
		*/
		ReferenceFrame_ITRF1993,

		/**
		* International Terrestrial Reference Frame 1994 (epoch 1993)
		*/
		ReferenceFrame_ITRF1994,

		/**
		* International Terrestrial Reference Frame 1996 (epoch 1997)
		*/
		ReferenceFrame_ITRF1996,

		/**
		* International Terrestrial Reference Frame 1997 (epoch 1997)
		*/
		ReferenceFrame_ITRF1997,

		/**
		* International Terrestrial Reference Frame 2000 (epoch 1997)
		*/
		ReferenceFrame_ITRF2000,

		/**
		* International Terrestrial Reference Frame 2005 (epoch 2000)
		*/
		ReferenceFrame_ITRF2005,

		/**
		* International Terrestrial Reference Frame 2008 (epoch 2005)
		*/
		ReferenceFrame_ITRF2008,

		/**
		* North American Datum 1983 (epoch 1997)
		*/
		ReferenceFrame_NAD83,

		/**
		* NAD83 Canadian Spatial Reference System (epoch 2002)
		*/
		ReferenceFrame_NAD83CSRS,

		/**
		* NAD83 (Continuously Operating Reference Station 1996) (epoch 2002)
		*/
		ReferenceFrame_NAD83CORS96,

		/**
		* European Terrestrial Reference System 1989 (epoch 1989)
		*/
		ReferenceFrame_ETRS89,

		/**
		* ETRF2000-R05 (epoch 2000)
		*/
		ReferenceFrame_ETRF2000R05,

		/**
		* Geocentric Datum of Australia 1994 (epoch 1994)
		*/
	    ReferenceFrame_GDA94,

		/**
		* Sistema de Referencia Geocentrico para las AmericaS 2000 (epoch 2000.4)
		*/
		ReferenceFrame_SIRGAS2000,

		/**
		* Sistema de Referencia Geocentrico para America del Sur 1995 (epoch 1995.4)
		*/
		ReferenceFrame_SIRGAS95,

		/**
		* SIRGAS-CON (epoch 2005)
		*/
		ReferenceFrame_SIRGASCON,

		/**
		* NAD83 (National Spatial Reference System 2011) (epoch 2010)
		*/
		ReferenceFrame_NAD832011,

		/**
		* NAD83 (National Spatial Reference System MA11) (epoch 2010)
		*/
		ReferenceFrame_NAD83MA11,

		/**
		* NAD83 (National Spatial Reference System PA11) (epoch 2010)
		*/
		ReferenceFrame_NAD83PA11,

		/**
		* RGF93v2 (epoch 2009)
		*/
		ReferenceFrame_RGF93v2,

		/**
		* CGCS2000 (epoch 2000).
		*/
		ReferenceFrame_CGCS2000,

		/**
		* New Zealand Geodetic Datum 2000 (epoch 2000)
		*/
		ReferenceFrame_NZGD2000,

		/**
		* Japanese Geodetic Datum 2000 (epoch 1997)
		*/
		ReferenceFrame_JGD2000,

		/**
		* Posiciones Geodesicas Argentinas 2007 (epoch 2006.632)
		*/
		ReferenceFrame_POSGAR07,

		/**
		* Reseau Geodesique des Antilles Francaises 2009 (epoch 2009)
		*/
		ReferenceFrame_RGAF09,

		/**
		* Reseau Geodesique Francais Guyane 1995 (epoch 1995)
		*/
		ReferenceFrame_RGFG95,

		/**
		* Reseau Geodesique de Nouvelle Caledonie 91-93 (epoch 1989)
		*/
		ReferenceFrame_RGNC9193,

		/**
		* Reseau Geodesique de la Reunion 1992 (epoch 1993)
		*/
		ReferenceFrame_RGR92,

		/**
		* Reseau Geodesique des Terres Australes et Antarctiques Francaises 2007 (epoch 2007.274)
		*/
		ReferenceFrame_RGTAAF07,

		/**
		* Marco Geocentrico Nacional de Referencia (epoch 1995.4)
		*/
		ReferenceFrame_MAGNASIRGAS,

		/**
		* Estonia 1997 (epoch 1997.56)
		*/
		ReferenceFrame_EST97,

		/**
		* International Terrestrial Reference Frame 2014 (epoch 2010)
		*/
		ReferenceFrame_ITRF2014,

		/**
		* Geocentric Datum of Australia 2020 (epoch 2020)
		*/
		ReferenceFrame_GDA2020,

		/**
		* NAD83 Canadian Spatial Reference System (epoch 1997)
		*/
		ReferenceFrame_NAD83CSRS1997,

		/**
		* NAD83 Canadian Spatial Reference System (epoch 2002)
		*/
		ReferenceFrame_NAD83CSRS2002,

		/**
		* NAD83 Canadian Spatial Reference System (epoch 2010)
		*/
		ReferenceFrame_NAD83CSRS2010
	};
}
#endif