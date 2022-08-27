#include "subsystems/CollectSub.h"

CollectSub::CollectSub(){
    m_collect = new rev::CANSparkMax(11,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
    s_collect = new frc::Solenoid(frc::PneumaticsModuleType::CTREPCM,4);
}

CollectSub::~CollectSub(){

}

void CollectSub::m_turn(bool code, double output){
    double percent = fabs(output);
    double direct = code ? +1.0 : -1.0 ;
    m_collect->Set(direct*percent);
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
    this->
}