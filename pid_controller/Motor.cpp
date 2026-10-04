#include "Motor.h"

void Motor::rotate(double torque) {
    if (torque > MAX_TORQUE){
        torque = MAX_TORQUE;
    }
    if (torque < -1 * MAX_TORQUE){
        torque = -1 * MAX_TORQUE;
    }
    speed += torque / inertia;
}
Motor::Motor(): speed(0), inertia(1), MAX_TORQUE(5) {}
Motor::Motor(double inertia): speed(0), inertia(inertia), MAX_TORQUE(5) {}
void Motor::setLoad(double new_inertia) {
  speed = inertia * speed / new_inertia;
}