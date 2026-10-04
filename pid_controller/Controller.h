#ifndef CONTROLLER
#define CONTROLLER

#include "Motor.h"
#include "PID.h"

class Controller {
PID * pid_module;
double target_speed;
public:
  Motor * motor;
  Controller(Motor * motor, double kp, double ki, double kd, double target_speed);
  double get_target_speed();
  void set_target_speed(double target_speed);
  void feed_err(double err);
};

#endif