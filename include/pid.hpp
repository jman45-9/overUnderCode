#ifndef PID_OBJECT_HEADER
#define PID_OBJECT_HEADER


#include "api.h"
#include <functional>

using namespace pros;
using namespace pros::literals;


namespace PID
{

struct PID_tuning
{
    double kp;
    double ki;
    double kd;
};

class PID_OBJ
{
    public:
        double p;
        double i;
        double d;
        double kp;
        double ki;
        double kd;

        double lastErr;

        PID_OBJ();

        double pidCalc(double target, double current);
};

} //namespace PID end 

#endif // PID_OBJECT_HEADER
