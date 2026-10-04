#include <vector>
#include <string>
#include <fstream>
#include "Controller.h"
#include <thread>
#include "SimulationResult.h"

using namespace std;


SimulationResult::SimulationResult(vector<Controller*> &controllers) : controllers(controllers) {}

void SimulationResult::simulate_ticks(int ticks){
  for (int t = 0; t < ticks; t++){
    string readings = "";
    vector<thread> threads;

    for (int c = 0; c < controllers.size(); c++){
      Controller c1 = *controllers[c];
      threads.push_back(thread(&Controller::feed_err, controllers[c], c1.get_target_speed() - c1.motor->speed));
    }

    for (auto& th : threads) {
      if (th.joinable()) {
        th.join();
      }
    }

    for (int c = 0; c < controllers.size(); c++){
      readings = readings + to_string(controllers[c] -> motor -> speed) + ",";
    }

    readings.pop_back();
    output.push_back(readings);
  }
}

void SimulationResult::clear(){
  output.clear();
}

void SimulationResult::export_csv(string filename){
  ofstream CSVFile(filename);
  CSVFile << "Motor1";
  for (int i = 1; i < controllers.size(); i++){
    CSVFile << ",Motor" << i + 1;
  } CSVFile << endl;
  for (int i = 0; i < output.size(); i++){
      CSVFile << output[i] << endl;
  }
  CSVFile.close();
}
