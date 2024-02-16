#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "api.h"
#include "../include/DriveTrain.hpp"
#include "pros/rotation.hpp"
# include <math.h>

#define _USE_MATH_DEFINES

using namespace pros;
using namespace pros::literals;

double inToDeg(double in, double wheelCir);
bool isAtDeg(double deg, Rotation sensor);
int sign(double input);

class Robot {
    public:
        Controller master;
        DriveTrain driveTrain;
        Motor intake;
        Motor fly1;
        Motor fly2;
        Motor_Group flys;
        ADIDigitalOut flicker;
        ADIDigitalOut flicker2;
        ADIDigitalOut endFlicker;
        bool flickerState = LOW;
        bool intakeOn;
        bool flysOn;

        Robot(int *driveMotors, int intakeMotor);
        void intakeToggle();
        void fireFlicker();
        void driveControl(Controller);
        void basicFwd(double, double);
        void basicTurn(double, double);
        void toggleFlys();
};

#endif //INCLUDE_ROBOT_H_
