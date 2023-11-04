#include "../include/auton.hpp"

void auton::basicCloseSide()
{
   robot.driveTrain.fwdAuton(20,0); 
}

void basicFarside()
{
    robot.firePuncher();
    robot.fireFlicker();
    robot.driveTrain.fwdAuton(5,0);
    robot.driveTrain.autonTurn(120,1);
}
