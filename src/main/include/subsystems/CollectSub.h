#pragma once
#include <frc/Solenoid.h>
#include <rev/CANSparkMax.h>
#include <cmath>

class CollectSub{
 public:
    CollectSub();
    ~CollectSub();
    void collect_init();
    /**
     * @brief 电机转动
     * @param
     * @param code: true为正转、false为反转
     * @param output: 百分比输出功率
     */
    void m_turn(bool code, double output=0.15);
    /**
     * 停止转动
     */
    void m_stop();
    /**
     * @brief 气缸伸出
     * @param
     * @param code: true为伸出、false为收回
     */
    void iscollect(bool code);
 private:
    rev::CANSparkMax* m_collect;
    frc::Solenoid* s_collect;
};