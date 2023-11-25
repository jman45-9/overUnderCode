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
        Imu inertSen;

        PID::PID_OBJ fwdPID;
        PID::PID_OBJ turnPID;

        int motorInit;
        
        DriveTrain(int *motors, int inertPort);
        void driveGo(double power);
        void turn(double power);
        void brake();
        bool isHeading(double target);
        double getDriveRotation();

        //turn funcs
        void turnAuton(double deg, bool left);
        void fwdAuton(double distance, bool fwd);
};
#endif //DRIVE_TRAIN_OBJ_HEAD
