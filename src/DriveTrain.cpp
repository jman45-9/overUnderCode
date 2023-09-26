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
    PID::PID_tuning fwdTuning, turnTuning;
    fwdTuning.kp = 1; fwdTuning.ki = 0; fwdTuning.kd = 0;
    turnTuning.kp = 1; turnTuning.ki = 0; turnTuning.kd = 0;
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


double DriveTrain::getCurrentRot()
{
    return this->inertSen.get_rotation();
}


