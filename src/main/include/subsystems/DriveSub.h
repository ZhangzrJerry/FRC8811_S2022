#pragma once
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <cmath>
//我个人感觉其实这个timer和joystick理应同级，从robocom中抽出作为全局信息生产者，当然这里的timer可以是独属于底盘的子timer
#include <frc/Timer.h>

using namespace units;

class DriveSub{
 public:
   DriveSub();
   ~DriveSub();
   /**
    * @brief 初始化底盘程序
    */
   void stop_drive();
   void drive(double x, double w, double max_percent=0.5);
   /**
    * @brief 自动阶段程序
    * @param
    * @param code "left:+1","rght:-1","back:0"
    */
   void auto_drive(int code, double val1=0, double val2 = 0);
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
   frc::Timer timer{};
};