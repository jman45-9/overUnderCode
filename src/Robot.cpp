#include "../include/Robot.hpp"

Robot::Robot(int *motors) :
            frontLeft (*motors),
            frontRight (*(motors + 1)),
            backLeft (*(motors + 2)),
            backRight (*(motors + 3)),
            centerLeft (*(motors + 4)),
            centerRight(*(motors + 5))
{

}

void Robot::driveGo(Controller controller)
{
        int leftStick = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        int rightStick = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

        this->frontLeft.move(leftStick);
        this->backLeft.move(leftStick);
        this->centerLeft.move(leftStick);

        this->frontRight.move(rightStick);
        this->backRight.move(rightStick);
        this->centerRight.move(rightStick);
}