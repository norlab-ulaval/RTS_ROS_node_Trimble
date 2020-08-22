#ifndef SALLY_OBSERVATIONLISTENER_H
#define SALLY_OBSERVATIONLISTENER_H

#include "Observations/ITrackingObservationsListener.h"

#include <string>
#include <vector>

enum ObservationsIndex
{
    HORIZONTAL_ANGLE_VECTOR = 0,
    VERTICAL_ANGLE_VECTOR = 1,
    DISTANCE_VECTOR = 2,
    TIMESTAMPSEC_VECTOR = 3,
    TIMESTAMPNSEC_VECTOR = 4,
    ERROR = 5
};
class ObservationListener : 
    public SSI::ITrackingObservationsListener
{

public:
    
    ObservationListener();

    ~ObservationListener();

    virtual void observationTracked(const SSI::TrackingObservationsEvent& event);

    std::vector<std::vector<double>> getObservations();

    int getSizeVector();

    int saveFile(std::string file_name, int precision);

private:

    std::vector<std::vector<double>> observations;
    int size_vector;

};

#endif
