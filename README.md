# PID Controller Simulation Project
## https://github.com/anjali50429/PID-Motor-Controller

## Team Members
* **Anay Datta [BE2025003]**
* **Surya Anjali K [IE2025018]**
* **Priyangi Gupta [BE2025022]**
* **Pramit B C [BE2025025]**

## Project Overview
This project is a C++ implementation of a PID controller applied to a motor simulation system. It performs a feedback loop system to regulate motor speed, logging motor speed over time into a CSV file graphical visualization.

---

## Features
* **Multifile Project**: Multiple `.h` and `.cpp` files brought together by a `Makefile` to manage project building
* **Time-Series Data Logging**: Automatically exports simulation stepsand motor speed to an output CSV file
* **NO AI USAGE**: We refrained from the use of coding agents to develop this project
---

## Project Structure
* **`main.cpp`**: Main function exists here.
* **`pid_controller/`**: 
  * `PID.cpp / .h`: PID Module initialised with Kp, Ki, Kd (gains).
  * `Motor.cpp / .h`: Models physical motor characteristics and response to control inputs.
  * `Controller.cpp / .h`: Manages interaction between the PID controller and the motor.
  * `SimulationResult.cpp / .h`: Handles data collection and formatting for export.
* **`Makefile`**: Build automation script.

---


## Architecture & Sequence Diagram
<img width="3286" height="2382" alt="image" src="https://github.com/user-attachments/assets/f1f65bc8-62db-45fd-8837-3f3b21c5d21f" />


## Getting Started & Execution

1. Build the project by running `make`:
   ```bash
   make
   ```
2. Execute the compiled simulation program:
   ```bash
   ./main
   ```
3. Open the generated **`output.csv`** file in **Microsoft Excel** to plot and analyze the motor speed on a graph.
