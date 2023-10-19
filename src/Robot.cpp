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
        intake(intakeMotor),
        puncherSensor(puncherSensor),
        puncher(6)
{
        this->intakeOn = 0;
        this->puncher.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        this->puncherSensor.set_reversed(1);
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

