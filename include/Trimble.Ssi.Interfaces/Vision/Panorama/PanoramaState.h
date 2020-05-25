#ifndef PANORAMASTATE_H
#define PANORAMASTATE_H
namespace SSI
{
	/**
	* Represents the running state of the panorama feature
	*/
	enum PanoramaState
	{
		/**
		* Represents a panorama which is not running
		*/
		Panorama_NotRunning,

		/**
		* Represents a panorama which is running
		*/
		Panorama_Running
	};
}

#endif        //  #ifndef PANORAMASTATE_H
