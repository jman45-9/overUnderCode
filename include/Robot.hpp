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

        Robot(int *motors);
        void driveGo(Controller controller);


};

#endif //INCLUDE_ROBOT_H_