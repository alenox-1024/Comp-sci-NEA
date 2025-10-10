#include <string>
#include "Rotor.h"
namespace enigma {
    Rotor::Rotor(std::string CharList, int turnover1Set, int turnover2Set) 
    {
        for (int i = 0; i < 26; i++) {
            shifts[i] = (int) CharList[i] - 65 - i;
            if (shifts[i] < 0) {
                shifts[i] += 26;
            }
            reverseShifts[(shifts[i] + i) % 26] = (26 - shifts[i]);
        };
        turnover[0] = turnover1Set;
        turnover[1] = turnover2Set;
    }

    // shifts character (represented by integer value n) when going in appropriate direction
    int Rotor::ShiftChar(int n, int pos, int ringSetting, bool forwardDirection) 
    {
        if (forwardDirection) {
            return (shifts[(pos + n - ringSetting) % 26] + n) % 26;
        } else {
            return (reverseShifts[(pos + n - ringSetting) % 26] + n) % 26;
        }
    }

    // checks if rotor is in turnover position (turnover latch engaged)
    bool Rotor::CheckTurnover(int rotorPosition)
    {
        if (rotorPosition == turnover[0] || rotorPosition == turnover[1]) {
            return true;
        };
        return false;
    }
}