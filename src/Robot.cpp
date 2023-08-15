#include "../include/Robot.hpp"

Robot::Robot(int *driveMotors, int intakeMotor) :
        frontLeft (*driveMotors),
        frontRight (*(driveMotors + 1)),
        backLeft (*(driveMotors + 2)),
        backRight (*(driveMotors + 3)),
        centerLeft (*(driveMotors + 4)),
        centerRight(*(driveMotors + 5)),
        intake(intakeMotor)
{
        this->intakeOn = 0;
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

void Robot::intakeToggle()
{
        this->intakeOn = !this->intakeOn;
        this->intake.move(127 * intakeOn);
}