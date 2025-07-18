#ifndef ROTOR_H
#define ROTOR_H
#include "cstdio"
#include "string"
namespace enigma {
    class Rotor {
        public:
        Rotor(std::string CharList, int turnover1Set, int turnover2Set);
        int ShiftChar(int characterToShift, bool forwardDirection);
        bool CheckTurnover(int x);
    };
}

#endif