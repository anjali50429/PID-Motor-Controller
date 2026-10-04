main: main.o Controller.o Motor.o PID.o SimulationResult.o
	g++ main.o Controller.o Motor.o PID.o SimulationResult.o -o main

main.o: main.cpp pid_controller/SimulationResult.h pid_controller/Controller.h pid_controller/Motor.h pid_controller/PID.h
	g++ -c main.cpp

Controller.o: pid_controller/Controller.cpp pid_controller/Controller.h pid_controller/Motor.h pid_controller/PID.h
	g++ -c pid_controller/Controller.cpp

Motor.o: pid_controller/Motor.cpp pid_controller/Motor.h
	g++ -c pid_controller/Motor.cpp

PID.o: pid_controller/PID.cpp pid_controller/PID.h
	g++ -c pid_controller/PID.cpp

SimulationResult.o: pid_controller/SimulationResult.cpp pid_controller/SimulationResult.h pid_controller/Controller.h pid_controller/Motor.h pid_controller/PID.h
	g++ -c pid_controller/SimulationResult.cpp

clean:
	rm -f *.o pid_controller