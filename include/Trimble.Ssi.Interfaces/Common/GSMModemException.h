#ifndef GSMMODEMEXCEPTION_H_
#define GSMMODEMEXCEPTION_H_
#include "SsiException.h"
namespace SSI
{

/**
 * The exception that is thrown when current operation failed due to internal modem problem.
 */
class GSMModemException: public SsiException
{
public:
    /**  Initializes a new instance of the GSMModemException class.
     * @param isLinkDown If set to true indicates that this exception occurred because the link to the modem is down.
     * @param isSimCardNotDetected If set to true indicates that this exception occurred because the internal sim card is not detected.
     * @param isSimCardPinWrong If set to true indicates that this exception occurred because the sim card Pin is wrong.
	 * @param isSimCardLocked If set to true indicates that this exception occurred because the sim card is locked.
	 */
    GSMModemException(bool isLinkDown, bool isSimCardNotDetected, bool isSimCardPinWrong, bool isSimCardLocked);

    virtual ~GSMModemException() throw ();

    /**
     * Gets a value indicating whether this exception occurred because the link to the modem is down.
     */
    bool isLinkDown() const;

    /**
     * Gets a value indicating whether this exception occurred because the internal sim card is not detected.
     */
    bool isSimCardNotDetected() const;

	/**
	* Gets a value indicating whether this exception occurred because the sim card Pin is wrong.
	*/
	bool isSimCardPinWrong() const;

	/**
     * Gets a value indicating whether this exception occurred because the sim card is locked.
     */
    bool isSimCardLocked() const;

private:
    bool _isLinkDown;
    bool _isSimCardNotDetected;
    bool _isSimCardPinWrong;
	bool _isSimCardLocked;
};

}
/* namespace SSI */

#endif /* GSMMODEMEXCEPTION_H_ */
