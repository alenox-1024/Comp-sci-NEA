#!/bin/bash
clang++ -c Rotor.cpp -o Rotor.o
clang++ -c EnigmaMachine.cpp -o EnigmaMachine.o
clang++ Rotor.o EnigmaMachine.o main.cpp -o main
./main
