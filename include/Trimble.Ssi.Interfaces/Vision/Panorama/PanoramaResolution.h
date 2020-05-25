#ifndef PANORAMARESOLUTION_H
#define PANORAMARESOLUTION_H
namespace  SSI
{
	/**
	* Represents the per pixel resolution of the panorama
	*/
	enum PanoramaResolution
	{
		/**
		* The coarse panorama resolution
		* 0.4 mrad
		*/
		PanoramaResolution_Coarse,

		/**
		* The medium panorama resolution
		* 0.09 mrad
		*/
		PanoramaResolution_Medium,

		/**
		* The fine panorama resolution
		* 0.02 mrad
		*/
		PanoramaResolution_Fine
	};
}
#endif        //  #ifndef PANORAMARESOLUTION_H
