#!/bin/bash
clang++ -c Rotor.cpp -o Rotor.o
clang++ -c BiHashMap.cpp -o BiHashMap.o
clang++ -c EnigmaMachine.cpp -o EnigmaMachine.o
clang++ -l pcrecpp Rotor.o BiHashMap.o EnigmaMachine.o main.cpp -o main
./main
