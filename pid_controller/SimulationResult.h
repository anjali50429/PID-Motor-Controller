#ifndef SIMULATION_RESULT
#define SIMULATION_RESULT

#include <vector>
#include <string>
#include <fstream>
#include "Controller.h"
#include <thread>

using namespace std;

class SimulationResult {
vector<Controller*> controllers;
vector<string> output;
public:
  SimulationResult(vector<Controller*> &controllers);
  void simulate_ticks(int ticks);
  void clear();
  void export_csv(string filename);
};

#endif