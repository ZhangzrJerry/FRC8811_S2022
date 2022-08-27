#include <frc/Solenoid.h>
#pragma once

class ClimbSub{
 public:
    ClimbSub();
    ~ClimbSub();
    /**
     * @brief 操控爬升臂
     * @param
     * @param code: true伸出、false收回
     */
    void control(bool code);
 private:
    frc::Solenoid* a;
    frc::Solenoid* b;
};