// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {
  YiZhongRen.init_com();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  YiZhongRen.init_com();
}

void Robot::AutonomousPeriodic() {
  YiZhongRen.auto_com();
}

void Robot::TeleopInit() {
  YiZhongRen.init_com();
}

void Robot::TeleopPeriodic() {
  YiZhongRen.tele_com();
}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
