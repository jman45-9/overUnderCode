#include "../include/auton.hpp"

/*void auton::basicCloseSide()
{
   robot.driveTrain.fwdAuton(20,0); 
}

void auton::basicFarside()
{
    robot.firePuncher();
    robot.fireFlicker();
    robot.driveTrain.fwdAuton(5,0);
    robot.driveTrain.turnAuton(120,1);
}*/

void auton::noPIDCloseSide()
{
    robot.basicFwd(1.0, -127.0);
}

void auton::noPIDFarside()
{
    robot.fireFlicker();
    robot.driveTrain.fwdAuton(1.0, -127.0);
    robot.driveTrain.turnAuton(1.0, 127.0);
}
