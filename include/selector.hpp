#ifndef AUTON_SELECTOR_CPP_HEADER
#define AUTON_SELECTOR_CPP_HEADER

#include <string>
#include "api.h"

/*include header for where the auton programs are stored*/
#include "auton.hpp"
/*------------------------------------------------------*/

#define PROS_USE_SIMPLE_NAMES

using namespace pros;

namespace selector
{
    struct autonData
    {
        std::string autonName;
        short int autonNumber;
        void (*autonFunction)();
    };

    autonData *autons;
        
    void selectorInit(short int autonCount);
    void getAutons(short int autonCount);
    void switchAuton();
    void cleanSelector();

}

#endif //AUTON_SELECTOR_CPP_HEADER
