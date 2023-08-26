#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "api.h"
#include "pros/rotation.hpp"
# include <math.h>

#define _USE_MATH_DEFINES

using namespace pros;
using namespace pros::literals;

double inToDeg(double in, double wheelCir);
bool isAtDeg(double deg, Rotation sensor);

class Robot {
    public:
        Motor topLeft;
        Motor topRight;
        Motor bottomLeft;
        Motor bottomRight;
        Motor centerLeft;
        Motor centerRight;
        Motor intake;
        Motor puncher;

        Rotation puncherSensor;

        bool intakeOn;

        Robot(int *driveMotors, int intakeMotor, int puncherSensor);
        void moveLeft(int voltage);
        void moveRight(int voltage);
        void driveGo(Controller controller);
        void intakeToggle();
        void firePuncher();

        void autonDrive(double in);
};

#endif //INCLUDE_ROBOT_H_