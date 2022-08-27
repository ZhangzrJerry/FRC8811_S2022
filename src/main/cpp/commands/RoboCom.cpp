#include "commands/RoboCom.h"

RoboCom::RoboCom(){

}

RoboCom::~RoboCom(){

}

void RoboCom::init_com(){
    // FSub.collect_init();
    CSub.climbinit();
    DSub.stop_drive();
}

void RoboCom::auto_com(){
    DSub.auto_drive(0,10.0,3.0);
}

void RoboCom::tele_com(){
    // 底盘操控部分
    double stick_x = this->filter(+m_stick->GetRawAxis(0));
    double stick_y = this->filter(-m_stick->GetRawAxis(5));
    double stick_pro = 0.5 + 0.5 * m_stick->GetRawAxis(3);
    DSub.drive(stick_x,stick_y,stick_pro);
    
    // 爬升操控部分
    if(m_stick->GetRawButton(5)){
        // 解锁爬升操控权限
        if(m_stick->GetRawButton(8)){
            CSub.control(true);
        }
        if(m_stick->GetRawButton(7)){
            CSub.control(false);
        }
    }

    // // 吸球操控部分
    // if(m_stick->GetRawButton(4)){
    //     FSub.changecollect();
    // }
    // if(FSub.getcollect()){
    //     FSub.m_turn(0.3*(m_stick->GetRawAxis(2)-0.5));
    // }
}

double RoboCom::filter(double x){
    if(fabs(x)<0.05)return 0;
    return x*x*x;
}