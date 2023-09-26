#include "../include/pid.hpp"
PID::PID_OBJ::PID_OBJ()
{
    /*
    this->kp = tuning->kp;
    this->ki = tuning->ki;
    this->kd = tuning->kd;

    this->getCurrent = funcs->getCurrent;
    this->action = funcs->action;
    this->endAction = funcs->endAction;
    this->successCond = funcs->successCond;
    */
}

double PID::PID_OBJ::pidCalc(double target, double current)
{
    this->p = target - current;
    this->i += this->p;
    this->d = this->p - this->lastErr;
    this->lastErr = this->p;
    return (this->p*this->kp)+(this->i*this->ki)+(this->d*this->kd);
}
