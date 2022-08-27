#include"subsystems/ClimbSub.h"

ClimbSub::ClimbSub(){
    a = new frc::Solenoid(frc::PneumaticsModuleType::CTRERPM,0);
    b = new frc::Solenoid(frc::PneumaticsModuleType::CTRERPM,1);
}

ClimbSub::~ClimbSub(){

}

void ClimbSub::control(bool code){
    a->Set(code);
    b->Set(code);
}