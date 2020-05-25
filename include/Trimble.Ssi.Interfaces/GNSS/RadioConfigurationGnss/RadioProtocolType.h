#ifndef RADIOPROTOCOL_H_
#define RADIOPROTOCOL_H_

namespace SSI
{
	/**
	* The radio over the air protocol type
	*/
	enum RadioProtocolType
	{
		RP_TrimTalk450S,	/**<TrimTalk 450S protocol */
		RP_TrimMark3,		/**<TrimMark 3 protocol  */
		RP_TrimMark2,		/**<TrimMark II / IIe protocol */
		RP_TT450S_HW,		/**<TT450S (HW)*/
		RP_Transparent,	    /**<Transparent protocol */
		RP_TransparentFST,	/**<Transparent FST protocol */
		RP_Satel			/**<Satel protocol */
	};
}
#endif
