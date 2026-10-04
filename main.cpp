#include <iostream>
#include <vector>

#include "pid_controller/SimulationResult.h"

using namespace std;

int main(){

  Motor m1(1);
  Motor m2(1);
  Controller c1(&m1, 0.1, 0.01, 0.1, 56.7);
  Controller c2(&m2, 0.2, 0.01, 0.05, 43.2);

  vector<Controller*> controllers;
  
  controllers.push_back(&c1);
  controllers.push_back(&c2);

  SimulationResult sim(controllers);

  sim.simulate_ticks(100);
  m1.setLoad(2); // load variations (change in inertia)
  sim.simulate_ticks(50);
  c2.set_target_speed(90.8); // changing target_speed
  sim.simulate_ticks(50);

  sim.export_csv("output.csv");

  return 0;
}

/*
- Multithreading
- Integration with Unity/Unreal Engine for simulation
- Multifile
- Automatic Visualization
*/

