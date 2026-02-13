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
            Rotor(std::string CharList, int turnover1Set, int turnover2Set); // constructs a rotor from a 26 letter string which represents the shifts, and information on the turnover notches
            int ShiftChar(int characterToShift, int positionOfRotor, int ringSetting, bool forwardDirection); // shifts the character
            bool CheckTurnover(int x); // checks if a position corresponds to a turnover notch
    };
}

#endif