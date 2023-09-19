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

class Robot {
    public:
        Motor intake;
        Motor puncher;

        Rotation puncherSensor;

        bool intakeOn;

        Robot(int *driveMotors, int intakeMotor, int puncherSensor);
        void intakeToggle();
        void firePuncher();
};

#endif //INCLUDE_ROBOT_H_
