#ifndef NTRIPSETUPEXCEPTION_H_
#define NTRIPSETUPEXCEPTION_H_
#include "SsiException.h"
namespace SSI
{
/**  The exception that is thrown when the NTRIP start failed.
 */
class NTRIPSetupException:public SsiException
{
public:
    /**  Initializes a new instance of the NTRIPSetupException class.
     * @param hasSetupFailed If set to true indicates that this exception occurred because the NTRIP socket setup failed.
     * @param isAuthorizationFaulty If set to true indicates that this exception occurred because the authorization parameters seems to be wrong.
     * @param isMountpointWrong If set to true indicates that this exception occurred because the mount point seems to be wrong.
     */
    NTRIPSetupException(const char* operationDescription, const char* message, int errorCode, bool hasSetupFailed, bool isAuthorizationFaulty, bool isMountpointWrong);

    virtual ~NTRIPSetupException() throw ();

    /**  Gets a value indicating whether this exception occurred because the NTRIP socket setup failed.
     */
    bool hasSetupFailed() const;

    /**  Gets a value indicating whether this exception occurred because the authorization parameters seems to be wrong.
     */
    bool isAuthorizationFaulty() const;

    /**  Gets a value indicating whether this exception occurred because the mount point seems to be wrong.
     */
    bool isMountpointWrong() const;

private:
    bool _hasSetupFailed;
    bool _isAuthorizationFaulty;
    bool _isMountpointWrong;
};
}
/* namespace SSI */

#endif /* NTRIPSETUPEXCEPTION_H_ */
