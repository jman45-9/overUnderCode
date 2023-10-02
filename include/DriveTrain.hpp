#ifndef DRIVE_TRAIN_OBJ_HEAD
#define DRIVE_TRAIN_OBJ_HEAD

#include "api.h"
#include "pid.hpp"

using namespace pros;
using namespace pros::literals;



class DriveTrain 
{
    public:
        Motor topLeft;
        Motor topRight;
        Motor bottomLeft;
        Motor bottomRight;
        Motor centerLeft;
        Motor centerRight;
        Imu inertSen;

        PID::PID_OBJ fwdPID;
        PID::PID_OBJ turnPID;

        int motorInit;
        
        DriveTrain(int *motors, int inertPort);
        void driveGo(Controller controller);
        void turn(double power);
        void brake();
        bool isHeading(double target);

        //turn funcs
        void turnAuton(double deg, bool left);
};
#endif //DRIVE_TRAIN_OBJ_HEAD
