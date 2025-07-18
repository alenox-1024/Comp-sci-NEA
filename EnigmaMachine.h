#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H
#include "Rotor.h"
namespace enigma {
    class EnigmaMachine {
        public:
            EnigmaMachine(Rotor* rotor1, Rotor* rotor2, Rotor* rotor3, Rotor* umkehrwalze) {};
            void SetPositions(int pos1, int pos2, int pos3) {}
            char Encrypt(char a){return a;};
    };
}
#endif