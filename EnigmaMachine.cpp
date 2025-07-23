#include "Rotor.h"
#include "EnigmaMachine.h"
#include <iostream>

namespace enigma {
    EnigmaMachine::EnigmaMachine(Rotor* rotor1, Rotor* rotor2, Rotor* rotor3, Rotor* umkehrwalze)
    {
        this->rotors[0] = rotor1;
        this->rotors[1] = rotor2;
        this->rotors[2] = rotor3;
        this->reflector = umkehrwalze;
    };

    void EnigmaMachine::SetPositions(int pos1, int pos2, int pos3) 
    {
        positions[0] = pos1;
        positions[1] = pos2;
        positions[2] = pos3;
    }

    char EnigmaMachine::Encrypt(char a)
    {
        int temp = ((int) a) - 65;
        positions[2]++;
        if (rotors[2] -> CheckTurnover(positions[2])) {
            positions[1]++;
            if (rotors[1] -> CheckTurnover(positions[1])) {
                positions[0]++;
            }
        }
        for (int i = 2; i >= 0; i--) {
            temp = rotors[i] -> ShiftChar(temp, positions[i],true);
        }
        temp = reflector -> ShiftChar(temp, 0,true);
        for (int i = 0; i <= 2; i++) {
            temp = rotors[i] -> ShiftChar(temp, positions[i], false);
        }
        a = (char) (temp + 65);
        return a;
    };
};