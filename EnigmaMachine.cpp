#include "Rotor.h"

namespace enigma {
    class EnigmaMachine {
        private:
            int encipheringCharacter;
            static Rotor reflector;
            int positions[3];
            static Rotor rotors[3];
        public:
            EnigmaMachine(Rotor rotor1, Rotor rotor2, Rotor rotor3, Rotor umkehrwalze)
            {
                rotors[0] = rotor1;
                rotors[1] = rotor2;
                rotors[2] = rotor3;
                reflector = umkehrwalze;
                int positions[3] = {0, 0, 0};
                int numRotors = 3;
            };

            void SetPositions(int pos1, int pos2, int pos3) {
                positions[0] = pos1;
                positions[1] = pos2;
                positions[2] = pos3;
            }

            char Encrypt(char a)
            {
                int temp = ((int) a) - 65;
                positions[2]++;
                if (rotors[2].CheckTurnover(positions[2])) {
                    positions[1]++;
                    if (rotors[1].CheckTurnover(positions[1])) {
                        positions[0]++;
                    }
                }
                for (int i = 2; i >= 0; i--) {
                    temp = rotors[i].ShiftChar(temp, true);
                }
                reflector.ShiftChar(temp, true);
                for (int i = 0; i <= 2; i++) {
                    temp = rotors[i].ShiftChar(temp, false);
                }
                a = (char) (temp + 65);
                return a;
            };
    };
}