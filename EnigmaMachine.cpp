#include "Rotor.h"
#include "EnigmaMachine.h"

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
        positions[0] = pos1 - 1;
        positions[1] = pos2 - 1;
        positions[2] = pos3 - 1;
    }
    
    void EnigmaMachine::SetRingstellungen(int ring1, int ring2, int ring3)
    {
        ringSettings[0] = ring1 - 1;
        ringSettings[1] = ring2 - 1;
        ringSettings[2] = ring3 - 1;
    }

    char EnigmaMachine::Encrypt(char a)
    {
        int temp = ((int) a) - 65;
        positions[2] = (positions[2]) % 26 + 1;
        // accounts for double-step in middle rotor
        if (rotors[1] -> CheckTurnover(positions[1])) {
            positions[1] = (positions[1]) % 26 + 1;
            positions[0] = (positions[0]) % 26 + 1;
        }
        if (rotors[2] -> CheckTurnover(positions[2])) {
            positions[1] = (positions[1]) % 26 + 1;
        }
        for (int i = 2; i >= 0; i--) {
            temp = rotors[i] -> ShiftChar(temp, positions[i], ringSettings[i], true);
        }
        temp = reflector -> ShiftChar(temp, 0, 0, true);
        for (int i = 0; i <= 2; i++) {
            temp = rotors[i] -> ShiftChar(temp, positions[i], ringSettings[i], false);
        }
        a = (char) (temp + 65);
        return a;
    };
};