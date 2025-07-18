#include <cstdio>
#include <string>
namespace enigma {
    class Rotor {
        protected:
            int shifts[26]; // stores the rotor's wiring
        private: 
            int reverseShifts[26]; // stores rotor shifts in reverse direction
            int turnover[2]; // sets where turnover latches are for a rotor, for single latch rotors, use {x, -1}
        public:
            Rotor(std::string CharList, int turnover1Set, int turnover2Set) 
            {
                for (int i = 0; i < 26; i++) {
                    shifts[i] = (int) CharList[i] - 65 - i;
                    reverseShifts[shifts[i]] = 0 - shifts[i];
                };
                turnover[0] = turnover1Set;
                turnover[1] = turnover2Set;
            }

            // shifts character (represented by integer value) when going in appropriate direction
            virtual int ShiftChar(int n, bool forwardDirection) 
            {
                if (forwardDirection) {
                    return (shifts[n] + n) % 26;
                } else {
                    return (reverseShifts[n] + n) % 26;
                }
            }

            // checks if rotor is in turnover position (turnover latch engaged)
            bool CheckTurnover(int rotorPosition)
            {
                if (rotorPosition == turnover[0] || rotorPosition == turnover[1]) {
                    return true;
                };
                return false;
            }
    };
}