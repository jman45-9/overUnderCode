#include "../include/Robot.hpp"

double inToDeg(double in, double wheelDiam)
{
        return (in / (M_PI * wheelDiam)) * 360;
}

bool isAtDeg(double deg, Rotation sensor)
{
        std::cout << sensor.get_position() << '\n';
        return sensor.get_position()/100 >= deg; 
}

Robot::Robot(int *driveMotors, int intakeMotor) :
        master(E_CONTROLLER_MASTER),
        driveTrain(driveMotors, 3),
        intake(intakeMotor),
        fly1(15);
        fly2(7),
        flys({fly1,fly2}),
        flicker('a', LOW)
{
        this->intakeOn = 0;
}



void Robot::intakeToggle()
{
        this->intakeOn = !this->intakeOn;
        this->intake.move((127*0.7) * intakeOn);
}



void Robot::fireFlicker()
{
    flickerState = !flickerState;
    this->flicker.set_value(flickerState);
}

void Robot::driveControl(Controller master)
{
    double leftStick = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
    double rightStick = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

    this->driveTrain.topLeft.move(leftStick);
    this->driveTrain.bottomLeft.move(leftStick);
    this->driveTrain.centerLeft.move(leftStick);

    this->driveTrain.topRight.move(rightStick);
    this->driveTrain.bottomRight.move(rightStick);
    this->driveTrain.centerRight.move(rightStick);
}

void Robot::basicFwd(double time, double power)
{
    this->driveTrain.topLeft.move(power);
    this->driveTrain.bottomLeft.move(power);
    this->driveTrain.centerLeft.move(power);

    this->driveTrain.topRight.move(power);
    this->driveTrain.bottomRight.move(power);
    this->driveTrain.centerRight.move(power);

    pros::delay(time * 1000);

    this->driveTrain.topLeft.brake();
    this->driveTrain.bottomLeft.brake();
    this->driveTrain.centerLeft.brake();

    this->driveTrain.topRight.brake();
    this->driveTrain.bottomRight.brake();
    this->driveTrain.centerRight.brake();
}

void Robot::toggleFlys()
{
    this->flysOn=!this->flysOn;
    if(flysOn)
        flys.move(127);
    else
        flys.brake();
}
