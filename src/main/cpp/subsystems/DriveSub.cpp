#include "subsystems/DriveSub.h"


DriveSub::DriveSub(){
    left = new ctre::phoenix::motorcontrol::can::TalonSRX(1);
    left_follow = new ctre::phoenix::motorcontrol::can::TalonSRX(2);
    left_follow->Follow(&left,ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
    rght = new ctre::phoenix::motorcontrol::can::TalonSRX(3);
    rght_follow = new ctre::phoenix::motorcontrol::can::TalonSRX(4);
    rght_follow->Follow(&rght,ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);

    this->init_drive();
}


DriveSub::~DriveSub(){

}

void DriveSub::drive(double x, double w, double max_percent){
    double left_speed,rght_speed;
    if(x>0){
        left_speed = x + w;
        rght_speed = x - w;
    }else{
        left_speed = x - w;
        rght_speed = x + w;
    }
    double max_speed = fabs(left_speed) > fabs(rght_speed) ? left_speed : rght_speed;
    double k_speed = fabs(max_percent) / max_speed;
    left->Set(ControlMode::PercentOutput,+direct*left_speed*k_speed);
    rght->Set(ControlMode::PercentOutput,-direct*rght_speed*k_speed);
    return;
}

void DriveSub::auto_drive(int code, double val1, double val2){
    // 我是个**，自动阶段不能过CENTER LINE
    // if(code==+1){
    //     this->stop_drive();
    // }else if(code==-1){
    //     this->stop_drive();
    // }else if(code==0){
        if(timer.Get().value()>val1){
            if(timer.Get().value()<val2){
                this->drive(-1.0,0.0,0.5);
            }else{
                this->stop_drive();
            }
        }else{
            this->stop_drive();
        }
    // }else{
    //     this->stop_drive();
    // }
    // return;
}

void DriveSub::init_drive(){
    left->Set(ctre::phoenix::motorcontrol::ControlMode::Disabled,0.0);
    rght->Set(ctre::phoenix::motorcontrol::ControlMode::Disabled,0.0);
    left->ConfigFactoryDefault();
    left_follow->ConfigFactoryDefault();
    rght->ConfigFactoryDefault();
    rght_follow->ConfigFactoryDefault();

    timer.Reset();
    timer.Start();
}