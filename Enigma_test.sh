#!/bin/bash
clang++ -c Rotor.cpp -o Rotor.o
clang++ -c BiHashMap.cpp -o BiHashMap.o
clang++ -c EnigmaMachine.cpp -o EnigmaMachine.o
clang++ -c GUI.cpp -o GUI.o
clang++ -l pcrecpp -l raylib Rotor.o BiHashMap.o EnigmaMachine.o GUI.o main.cpp -o main
./main
