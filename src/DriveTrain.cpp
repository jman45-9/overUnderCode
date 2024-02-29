#include "../include/DriveTrain.hpp"


int debugCounter =0;
DriveTrain::DriveTrain(int *motors, int inertPort) :
    topLeft (*motors, E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    topRight (*(motors + 1), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    bottomLeft (*(motors + 2),E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    bottomRight (*(motors + 3), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    centerLeft (*(motors + 4), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    centerRight(*(motors + 5), E_MOTOR_GEAR_GREEN, 0, E_MOTOR_ENCODER_DEGREES),
    inertSen(inertPort),
    fwdPID(),
    turnPID()
{
    this->turnPID.kp=7.5;this->turnPID.ki=0.00;this->turnPID.kd=50;
    this->fwdPID.kp=1;this->fwdPID.ki=0;this->fwdPID.kd=0;
    topLeft.set_brake_mode(E_MOTOR_BRAKE_COAST); 
    topRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
    bottomLeft.set_brake_mode(E_MOTOR_BRAKE_COAST);
    bottomRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
    centerLeft.set_brake_mode(E_MOTOR_BRAKE_COAST);
    centerRight.set_brake_mode(E_MOTOR_BRAKE_COAST);
}

void DriveTrain::driveGo(double power)
{

        this->topLeft.move(power);
        this->bottomLeft.move(power);
        this->centerLeft.move(power);

        this->topRight.move(power);
        this->bottomRight.move(power);
        this->centerRight.move(power);
}

void DriveTrain::turn(double power)
{

        this->topLeft.move(power);
        this->bottomLeft.move(power);
        this->centerLeft.move(power);

        this->topRight.move(-power);
        this->bottomRight.move(-power);
        this->centerRight.move(-power);
}



//Right by default
void DriveTrain::brake()
{
    this->topLeft.brake();
    this->bottomLeft.brake();
    this->centerLeft.brake();

    this->topRight.brake();
    this->bottomRight.brake();
    this->centerRight.brake();
}

bool DriveTrain::isHeading(double target)
{
    if(debugCounter > 9)
    {
        std::cerr << "headingPassedVal = " << target << '\n';
        debugCounter = 0;
    }
    debugCounter++;
    return  this->inertSen.get_rotation() >= target 
        && this->inertSen.get_rotation() <= 1 + target;
}

double DriveTrain::getDriveRotation()
{
    double totRot = this->topLeft.get_position() +
    this->bottomLeft.get_position() +
    this->centerLeft.get_position() +
    this->topRight.get_position() +
    this->bottomRight.get_position() +
    this->centerRight.get_position();

    return totRot / 6;
}

void DriveTrain::turnAuton(double deg, bool left)
{
    int successCycles = 0;
    this->turnPID.reset(deg);

    double initRot = this->inertSen.get_rotation();
    std::cerr << "initRotVal = " << initRot << '\n';
    std::cerr << "passVal = " << initRot + deg << '\n';

    int testVal = 0;
    int direcConst;

    double target = initRot + deg;
           
    while(true)
    {
        double calc = turnPID.pidCalc(target,this->inertSen.get_rotation());
        if (left)
        {
            this->turn(calc);
            direcConst = -1;
          }
        else
        {
            this->turn(- calc);
            direcConst = 1;
        }

        
        if(isHeading(target * direcConst))
        {
            if(successCycles == 2)
            {
                this->brake();
                return;
            }
            successCycles++;
        } else
            successCycles = 0;

        pros::delay(5);
    }
}

void DriveTrain::fwdAuton(double distance)
{
    double wheelDiam = 3.25;
    double degress = ((distance / (wheelDiam*M_PI)) * 360);
    int successCycles = 0;
    this->fwdPID.reset(distance);
    double initMtrRot = getDriveRotation();
    double target = degress + initMtrRot;
           
    while(true)
    {
        double curDeg = getDriveRotation();
        double calc = fwdPID.pidCalc(target, curDeg);
        this->driveGo(calc);
        
        if(curDeg >= target && curDeg <= target+1 )
        {
            if(successCycles == 4)
            {
                this->brake();
                return;
            }
            successCycles++;
        } else
            successCycles = 0;

        pros::delay(5);
    }
}

void DriveTrain::mathFwd(double distance)
{
    double moveAmmount = (distance / 3.25) * 360;

    this->topLeft.move_relative(moveAmmount, 200);
    this->bottomLeft.move_relative(moveAmmount, 200);
    this->centerLeft.move_relative(moveAmmount, 200);

    this->topRight.move_relative(moveAmmount, 200);
    this->bottomRight.move_relative(moveAmmount, 200);
    this->centerRight.move_relative(moveAmmount, 200);
}

