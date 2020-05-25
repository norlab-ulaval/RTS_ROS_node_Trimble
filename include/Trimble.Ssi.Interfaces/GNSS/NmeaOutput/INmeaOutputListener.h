#ifndef INMEAOUTPUTLISTENER_H_
#define INMEAOUTPUTLISTENER_H_

#include "NmeaOutput.h"
namespace SSI
{

class INmeaOutputListener
{
public:
    virtual ~INmeaOutputListener();

    virtual void onNmeaOutput(const NmeaOutput & nmeaOuput)=0;
};

} /* namespace SSI */

#endif /* INMEADATALISTENER_H_ */
