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

void auton::matchLoad()
{
    robot.driveTrain.mathFwd(17);
    pros::delay(1.8 * 1000);
    robot.driveTrain.turnAuton(-90, 0);
    robot.intake.move(100);
    robot.driveTrain.mathFwd(-5);
    pros::delay(0.4*1000);
    robot.intake.brake();
    robot.driveTrain.turnAuton(180, 0);
    robot.driveTrain.mathFwd(-7.8);
    pros::delay(2.5* 1000);
    robot.driveTrain.mathFwd(1);
    pros::lcd::set_text(1, "done");
}

