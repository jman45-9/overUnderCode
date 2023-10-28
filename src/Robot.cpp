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

Robot::Robot(int *driveMotors, int intakeMotor, int puncherSensor) :
        master(E_CONTROLLER_MASTER),
        driveTrain(driveMotors, 3),
        intake(intakeMotor),
        puncherSensor(puncherSensor),
        puncher(7),
        flicker('a', LOW)
{
        this->intakeOn = 0;
        this->puncher.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        this->puncherSensor.set_reversed(0);
        std::cout << "test 2" << '\n';
        std::cout << this->puncherSensor.get_position() << '\n';
        this->puncherSensor.reset_position();
        std::cout << this->puncherSensor.get_position() << '\n';
}



void Robot::intakeToggle()
{
        this->intakeOn = !this->intakeOn;
        this->intake.move((127*0.7) * intakeOn);
}

void Robot::firePuncher()
{
        this->puncherSensor.reset_position();
        this->puncher.move(127);
        int counter = 0;
        while(!isAtDeg(270, this->puncherSensor))
        {
                std::cout << this->puncherSensor.get_position();
                pros::delay(10);
        }
        this->puncher.brake();
        pros::delay(1000);
        this->puncher.move(127);
        while(!isAtDeg(360, this->puncherSensor))
                pros::delay(10);
        this->puncher.brake();
        this->puncherSensor.reset_position();
}

void Robot::fireFlicker()
{
    flickerState = !flickerState;
    this->flicker.set_value(flickerState);
}

void Robot::driveControl()
{
    double leftStick = this->master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
    double rightStick = this->master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

    this->driveTrain.topLeft.move(leftStick);
    this->driveTrain.bottomLeft.move(leftStick);
    this->driveTrain.centerLeft.move(leftStick);

    this->driveTrain.topRight.move(rightStick);
    this->driveTrain.bottomRight.move(rightStick);
    this->driveTrain.centerRight.move(rightStick);
}
