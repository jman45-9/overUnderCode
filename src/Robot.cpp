#include "../include/Robot.hpp"

double inToDeg(double in, double wheelDiam)
{
        return (in / (M_PI * wheelDiam)) * 360;
}

Robot::Robot(int *driveMotors, int intakeMotor, int puncherSensor) :
        topLeft (*driveMotors, E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
        topRight (*(driveMotors + 1), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
        bottomLeft (*(driveMotors + 2),E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
        bottomRight (*(driveMotors + 3), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
        centerLeft (*(driveMotors + 4), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
        centerRight(*(driveMotors + 5), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
        intake(intakeMotor),
        puncherSensor(puncherSensor)
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

void Robot::autonDrive(double in)
{
        double deg = inToDeg(in, 2);

        this->topLeft.move_absolute(deg, 200);
        this->bottomLeft.move_absolute(deg, 200);
        this->centerLeft.move_absolute(deg, 200);

        this->topRight.move_absolute(deg, 200);
        this->bottomRight.move_absolute(deg, 200);
        this->centerRight.move_absolute(deg, 200);
}

