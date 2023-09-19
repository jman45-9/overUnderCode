#ifndef DRIVE_TRAIN_OBJ_HEAD
#define DRIVE_TRAIN_OBJ_HEAD

#include "api.h"

using namespace pros;
using namespace pros::literals;

struct PidTuning 
{
    double kp;
    double ki;
    double kd;
}

class DriveTrain 
{
    public:
        Motor topLeft;
        Motor topRight;
        Motor bottomLeft;
        Motor bottomRight;
        Motor centerLeft;
        Motor centerRight;
        
        DriveTrain(int *motors);
        void pidFunc(double target, bool turning);
}
#endif //DRIVE_TRAIN_OBJ_HEAD
