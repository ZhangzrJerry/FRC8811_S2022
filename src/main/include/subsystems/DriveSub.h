#pragma once
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
class DriveSub{
 public:
    DriveSub();
    ~DriveSub();
    void drive();
 private:
    ctre::phoenix::motorcontrol::can::TalonSRX* left;
    ctre::phoenix::motorcontrol::can::TalonSRX* left_follow;
    ctre::phoenix::motorcontrol::can::TalonSRX* rght;
    ctre::phoenix::motorcontrol::can::TalonSRX* rght_follow;
};