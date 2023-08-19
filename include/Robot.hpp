#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "api.h"
#include <type_traits>

using namespace pros;
using namespace pros::literals;

double inToDeg(double deg, double wheelCir);

class Robot {
    public:
        Motor topLeft;
        Motor topRight;
        Motor bottomLeft;
        Motor bottomRight;
        Motor centerLeft;
        Motor centerRight;
        Motor intake;

        bool intakeOn;

        Robot(int *driveMotors, int intakeMotor);
        void moveLeft(int voltage);
        void moveRight(int voltage);
        void driveGo(Controller controller);
        void intakeToggle();

};

#endif //INCLUDE_ROBOT_H_