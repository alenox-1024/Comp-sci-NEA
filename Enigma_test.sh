#!/bin/bash
clang++ -c Rotor.cpp -o Rotor.o
clang++ -c BiHashMap.cpp -o BiHashMap.o
clang++ -c EnigmaMachine.cpp -o EnigmaMachine.o
clang++ -c GUI.cpp -o GUI.o
clang++ -c Settings.cpp -o Settings.o
clang++ -l pcrecpp -l raylib Settings.o Rotor.o BiHashMap.o EnigmaMachine.o GUI.o main.cpp -o main
./main
