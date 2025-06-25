#include "Rotor.h"
#include "Reflector.h"

namespace enigma {
    class EnigmaMachine {
        private:
            int encipheringCharacter;
            Rotor Rotors[8]; 
            Reflector Reflectors[3];
        public:
            EnigmaMachine()
            {
                Rotor[0] = new Rotor([]);
            }
    };
}