#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "api.h"

using namespace pros;
using namespace pros::literals;

class Robot {
    public:
        Motor frontLeft;
        Motor frontRight;
        Motor backLeft;
        Motor backRight;
        Motor centerLeft;
        Motor centerRight;
        Motor intake;

        bool intakeOn;

        Robot(int *driveMotors, int intakeMotor);
        void driveGo(Controller controller);
        void intakeToggle();

};

#endif //INCLUDE_ROBOT_H_