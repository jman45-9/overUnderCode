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
    robot.basicFwd(1.250, -127.0);
}

void auton::noPIDFarside()
{
    robot.fireFlicker();
}

void auton::goodAuton()
{
    robot.basicFwd(1.250, -127.0);
    robot.basicFwd(0.250,127);
    robot.driveTrain.turn(-127);
    delay(250);
    robot.driveTrain.brake();
    robot.basicFwd(1.250,-127.0);
    robot.fireFlicker();
    robot.basicFwd(1.250,-127.0);

}

