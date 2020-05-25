#ifndef NMEAOUTPUT_H_
#define NMEAOUTPUT_H_
#include <string>
namespace SSI
{

class NmeaOutput
{
public:
    NmeaOutput(const  std::string& nmeaOutputString);
    std::string getOutput();
    virtual ~NmeaOutput();
private:
    std::string _nmeaOutputString;
};

} /* namespace SSI */

#endif /* NMEAOUTPUT_H_ */
