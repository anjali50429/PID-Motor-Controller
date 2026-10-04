#ifndef PID_MODULE
#define PID_MODULE

class PID {
public:
  double kp,ki,kd;
  double p,i,d;
  double prev_err;
  PID(double kp, double ki, double kd);
  double update(double err);
};

#endif