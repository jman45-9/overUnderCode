#include "../include/Robot.hpp"

double inToDeg(double in, double wheelDiam)
{
        return (in / (M_PI * wheelDiam)) * 360;
}

bool isAtDeg(double deg, Rotation sensor)
{
        return sensor.get_position()/100 >= deg; 
}

Robot::Robot(int *driveMotors, int intakeMotor, int puncherSensor) :
        topLeft (*driveMotors, E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
        topRight (*(driveMotors + 1), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
        bottomLeft (*(driveMotors + 2),E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
        bottomRight (*(driveMotors + 3), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
        centerLeft (*(driveMotors + 4), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
        centerRight(*(driveMotors + 5), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
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

void Robot::firePuncher()
{
        this->puncherSensor.reset_position();
        this->puncher.move(127);
        int counter = 0;
        while(!isAtDeg(270, this->puncherSensor))
                pros::delay(10);
        this->puncher.brake();
        pros::delay(1000);
        this->puncher.move(127);
        while(!isAtDeg(360, this->puncherSensor))
                pros::delay(10);
        this->puncher.brake();
        this->puncherSensor.reset_position();
}

