#include "../include/Robot.hpp"

double inToDeg(double deg, double wheelCir)
{
        
}

Robot::Robot(int *driveMotors, int intakeMotor) :
        topLeft (*driveMotors),
        topRight (*(driveMotors + 1), 1),
        bottomLeft (*(driveMotors + 2)),
        bottomRight (*(driveMotors + 3), 1),
        centerLeft (*(driveMotors + 4), 1),
        centerRight(*(driveMotors + 5)),
        intake(intakeMotor)
{
        this->intakeOn = 0;
}

void Robot::driveGo(Controller controller)
{
        int leftStick = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        int rightStick = controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

        this->topLeft.move(leftStick);
        this->bottomLeft.move(leftStick);
        this->centerLeft.move(leftStick);

        this->topRight.move(rightStick);
        this->bottomRight.move(rightStick);
        this->centerRight.move(rightStick);
}

void Robot::intakeToggle()
{
        this->intakeOn = !this->intakeOn;
        this->intake.move(127 * intakeOn);
}
