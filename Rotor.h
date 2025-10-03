#ifndef ROTOR_H
#define ROTOR_H
#include <cstdio>
#include <string>
namespace enigma {
    class Rotor {
        private:
            int shifts[26]; // stores the rotor's wiring
            int reverseShifts[26]; // stores rotor shifts in reverse direction
            int turnover[2]; // sets where turnover latches are for a rotor, for single latch rotors, use {x, -1}
        public:
            Rotor(std::string CharList, int turnover1Set, int turnover2Set);
            int ShiftChar(int characterToShift, int positionOfRotor, int ringSetting, bool forwardDirection);
            bool CheckTurnover(int x);
    };
}

#endif