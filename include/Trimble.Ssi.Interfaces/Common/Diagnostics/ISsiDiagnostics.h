#ifndef ISSIDIAGNOSTICS_H_
#define ISSIDIAGNOSTICS_H_

#include "ISsiInterface.h"
#include "IRawMessageListener.h"

namespace SSI
{

    /**
     * Provides members to access diagnostic features of the instrument.
     */
    class ISsiDiagnostics : public ISsiInterface
    {
    public:
        virtual ~ISsiDiagnostics();

        /**
         * Sends set command
         * @param id the type
         * @param command the command
         * @param length the command length
         * @param responseId the response type
         */
        virtual void sendSetCommand(unsigned char id, const unsigned char* command, unsigned int length, unsigned char responseId) = 0;

        /**
        * Sends get command
        * @param id the type
        * @param command the command
        * @param length the command length
        * @param responseId the response type
        * @param response the response buffer
        * @param maxSize  the size of response buffer
        * @return response byte count
        */
        virtual unsigned int sendGetCommand(unsigned char id, const unsigned char* command, unsigned length, unsigned char responseId, unsigned char* response, unsigned int maxSize) = 0;

        /**
        * register a listener for listening.
        * @param IRawMessageListener to listen
        */
        virtual void addRawMessageListener(IRawMessageListener& listener) = 0;

        /**
        * unsubscribe a listener from listening.
        * @param IRawMessageListener to listen
        */
        virtual void removeRawMessageListener(IRawMessageListener& listener) = 0;
    };

} /* namespace SSI */

#endif /* ISSIDIAGNOSTICS_H_ */
