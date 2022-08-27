#pragma once
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <cmath>
class DriveSub{
 public:
   DriveSub();
   ~DriveSub();
   /**
    * @brief 初始化底盘程序
    */
   void init_drive();
   void drive(double x, double w, double max_percent=0.5);
   /**
    * @brief 自动阶段程序
    * @param
    * @param code "left","rght","back","stay&back:stay out of this function"
    */
   void auto_drive(int code);
 private:
   /**
    * @brief 机器人方向
    * @param +1或-1
    */
   int direct = +1; 
   ctre::phoenix::motorcontrol::can::TalonSRX* left;
   ctre::phoenix::motorcontrol::can::TalonSRX* left_follow;
   ctre::phoenix::motorcontrol::can::TalonSRX* rght;
   ctre::phoenix::motorcontrol::can::TalonSRX* rght_follow;
};