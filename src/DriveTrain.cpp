#include "../include/DriveTrain.hpp"

DriveTrain::DriveTrain(int *motors, int inertPort) :
    topLeft (*motors, E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    topRight (*(motors + 1), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
    bottomLeft (*(motors + 2),E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    bottomRight (*(motors + 3), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
    centerLeft (*(motors + 4), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
    centerRight(*(motors + 5), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    inertSen(inertPort),
    fwdPID(),
    turnPID()
{
    this->turnPID.kp=1;this->turnPID.ki=0;this->turnPID.kd=0;
}

void DriveTrain::driveGo(Controller controller)
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

void DriveTrain::turnAuton(double deg, bool left)
{
    int successCycles = 0;
    this->turnPID.reset(deg);
           
    while(true)
    {
        double calc = turnPID.pidCalc(deg,this->inertSen.get_rotation());
        if (left)
            this->turn(calc);
        else
            this->turn(calc);
    }
}

//Right by default
void DriveTrain::turn(double power)
{
    this->topLeft.move(power);
    this->bottomLeft.move(power);
    this->centerLeft.move(power);

    this->topRight.move(- power);
    this->bottomRight.move(- power);
    this->centerRight.move(- power);
}