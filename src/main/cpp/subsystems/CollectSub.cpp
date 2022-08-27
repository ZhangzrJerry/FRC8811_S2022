#include "subsystems/CollectSub.h"

CollectSub::CollectSub(){
    m_collect = new rev::CANSparkMax(11,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
    s_collect = new frc::Solenoid(frc::PneumaticsModuleType::CTREPCM,4);
}

CollectSub::~CollectSub(){

}

void CollectSub::m_turn(double output){
    m_collect->Set(output);
}

void CollectSub::m_stop(){
    m_collect->StopMotor();
    m_collect->ClearFaults();
}

void CollectSub::iscollect(bool code){
    s_collect->Set(code);
}

void CollectSub::collect_init(){
    this->m_stop();
    this->iscollect(false);
}

void CollectSub::changecollect(){
    s_collect->Set(!s_collect->Get());
}

void CollectSub::getcollect(){
    return s_collect->Get();
}