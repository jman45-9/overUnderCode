#include "../include/selector.hpp"

void selector::selectorInit(short int autonCount)
{
    if(!lcd::is_initialized())
    {
        lcd::initialize();
    }
    lcd::clear();
    lcd::set_text(1, "Select Auton");

    for(int iii = 0; autonCount > iii; iii++)
    {
        lcd::set_text((selector::autons+iii)->autonNumber + 3,
                (selector::autons+iii)->autonName);
    }

    lcd::register_btn1_cb(selector::switchAuton);
}

void selector::getAutons(short int autonCount)
{
    selector::autons = (selector::autonData *)(malloc(sizeof(selector::autonData)*autonCount));
    /*add autons to the array here*/
    (selector::autons)->autonName = "MATCH_LOAD-SIDE";
    (selector::autons)->autonNumber = 0;
    (selector::autons)->autonFunction = &(auton::noPIDCloseSide);

    (selector::autons)->autonName = "SKILLS";
    (selector::autons)->autonNumber = 2;
    (selector::autons)->autonFunction = &(auton::basicFarSide);
    /*----------------------------*/
}


void selector::switchAuton()
{
}

void selector::cleanSelector()
{
    free(selector::autons);
}
