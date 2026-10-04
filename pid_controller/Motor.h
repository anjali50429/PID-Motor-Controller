#ifndef MOTOR
#define MOTOR

class Motor {
protected:
  double MAX_TORQUE;
  double inertia;
public:
  double speed;
  void rotate(double torque);
  Motor();
  Motor(double inertia);
  void setLoad(double new_inertia);
};

#endif