#include "Motor.h"
#include "PID.h"
#include "Controller.h"

Controller::Controller(Motor * motor, double kp, double ki, double kd, double target_speed) : motor(motor), target_speed(target_speed) {
  pid_module = new PID(kp, ki, kd);
}

double Controller::get_target_speed(){ return target_speed; }

void Controller::set_target_speed(double target_speed) { this -> target_speed = target_speed; }

void Controller::feed_err(double err){
  double torque = pid_module -> update(err);
  motor -> rotate(torque);
}