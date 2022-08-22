#include "subsystems/DriveSub.h"


DriveSub::DriveSub(){
    left = new ctre::phoenix::motorcontrol::can::TalonSRX(1);
    left_follow = new ctre::phoenix::motorcontrol::can::TalonSRX(2);
    rght = new ctre::phoenix::motorcontrol::can::TalonSRX(3);
    rght_follow = new ctre::phoenix::motorcontrol::can::TalonSRX(4);
    left_follow->Follow(&left,ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
    rght_follow->Follow(&rght,ctre::phoenix::motorcontrol::FollowerType::FollowerType_PercentOutput);
}


DriveSub::~DriveSub(){

}