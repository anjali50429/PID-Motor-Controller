#include "PID.h"

PID::PID(double kp, double ki, double kd): kp(kp), ki(ki), kd(kd), prev_err(0) {}

double PID::update(double err){
  p = err;
  i += err;
  d = err - prev_err;
  prev_err = err;
  return kp*p + ki*i + kd*d;
} 