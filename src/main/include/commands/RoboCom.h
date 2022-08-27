#pragma once
#include "subsystems/ClimbSub.h"
// #include "subsystems/CollectSub.h"
#include "subsystems/DriveSub.h"
#include <frc/Joystick.h>

class RoboCom{
 public:
    RoboCom();
    ~RoboCom();
    void init_com();
    void auto_com();
    void tele_com();
 private:
    double filter(double x);
    frc::Joystick *m_stick = new frc::Joystick(0);
    /**
     * 爬升子系统
     */
    ClimbSub CSub;
    /**
   //   * 收球子系统,按F拾取
   //   */
   //  CollectSub FSub;
    /**
     * 底盘子系统
     */
    DriveSub DSub;
};