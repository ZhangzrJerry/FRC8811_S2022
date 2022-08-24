#include "subsystems/DriveSub.h"


DriveSub::DriveSub(){
    left = new ctre::phoenix::motorcontrol::can::TalonSRX(1);
    left_follow = new ctre::phoenix::motorcontrol::can::TalonSRX(2);
    left_follow->Follow(&left,ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
    rght = new ctre::phoenix::motorcontrol::can::TalonSRX(3);
    rght_follow = new ctre::phoenix::motorcontrol::can::TalonSRX(4);
    rght_follow->Follow(&rght,ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
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
    double max_speed = left_speed > rght_speed ? left_speed : rght_speed;
    double k_speed = max_percent / max_speed;
    left->Set(ControlMode::PercentOutput,+direct*left_speed*k_speed);
    rght->Set(ControlMode::PercentOutput,-direct*rght_speed*k_speed);
    return;
}

void DriveSub::auto_drive(int code){
    if(code=="left"){

    }else if(code=="rght"){
        
    }else if(code=="back"){
-
    }else{

    }
}