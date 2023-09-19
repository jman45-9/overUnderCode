#include "../include/DriveTrain.hpp"

DriveTrain::DriveTrain(int *motors) :
    topLeft (*driveMotors, E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    topRight (*(driveMotors + 1), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
    bottomLeft (*(driveMotors + 2),E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    bottomRight (*(driveMotors + 3), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
    centerLeft (*(driveMotors + 4), E_MOTOR_GEAR_GREEN, 1, E_MOTOR_ENCODER_DEGREES),
    centerRight(*(driveMotors + 5), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
{
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

void pidFunc(double target, bool turning, PidTuning *tuningInfo)
{
    double p,i,d;
    double kp=tuningInfo->kp,ki=turningInfo->ki,kd=;
    double lastErr=target;
    double successCycles=0;
    while (true) {
        double current = inertial.get_rotation();
        p = target - current;
        i += p;
        d = p - lastErr;
        double calc = (p*kp)+(i*ki)+(d*kd);
        std::cout << calc << '\n';
        motor.move(calc);
        lastErr = p; 
        if (isHeading(target, inertial))
        {
            if (successCycles == 4)
                motor.brake();
            
            successCycles++;
        } else
        {
            successCycles = 0;
        }
        pros::delay(5);
    }
}



