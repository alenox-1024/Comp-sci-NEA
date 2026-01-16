#include "Settings.h"
#include <string>

namespace enigma {
    int Settings::InterpretNumeralRecursive(std::string input, int i) 
    {
        int total = 0;
        if (i < input.length()) {
            total = InterpretNumeralRecursive(input, i+1);
        } else {
            if (input[i] == 'I') {
                return 1;
            } else if (input[i] == 'V') {
                return 5;
            } else if (input[i] == 'X') {
                return 10;
            } else if (input[i] == 'L') {
                return 50;
            } else if (input[i] == 'C') {
                return 100;
            } else if (input[i] == 'D') {
                return 500;
            } else if (input[i] == 'M') {
                return 1000;
            } 
        }
        if (input[i] == 'I') {
            if (input[i+1] == 'V' || input[i+1] == 'X') {
                return total - 1;
            } else {
                return total + 1;
            }
        } else if (input[i] == 'V') {
            return total + 5;
        } else if (input[i] == 'X') {
            if (input[i+1] == 'L' || input[i+1] == 'C') {
                return total - 10;
            } else {
                return total + 10;
            }
        } else if (input[i] == 'L') {
            return total + 50;
        } else if (input[i] == 'C') {
            if (input[i+1] == 'D' || input[i+1] == 'M') {
                return total - 100;
            } else {
                return total + 100;
            }
        } else if (input[i] == 'D') {
            return total + 500;
        } else if (input[i] == 'M') {
            return total + 1000;
        } else {
            return total;
        }
    }
    int Settings::InterpretRotorSettingLetter(char letter) {
        return ((int) letter - 64);
    }
    void Settings::SetSettings(std::string rotorInput[3], char RotorSettingInput[3], int ringSettingInput[3], std::string steckerBrettStringInput, std::string plainTextInput, char reflectorInput) {
        for (int i = 0; i < 3; i++) {
            rotors[i] = InterpretNumeralRecursive(rotorInput[i], 0);
            rotorSettings[i] = InterpretRotorSettingLetter(RotorSettingInput[i]);
            ringSettings[i] = ringSettingInput[i];
        }
        plainText = plainTextInput;
        steckerBrettString = steckerBrettStringInput;
        reflectorSetting = ((int) reflectorInput - 65);
    }
    void Settings::SetStatus(bool x) 
    {
        endProgram = x;
    }
    int Settings::ReturnRotor(int i)
    {
        return rotors[i];
    }
    int Settings::ReturnReflector()
    {
        return reflectorSetting;
    }
    int Settings::ReturnRotorSetting(int i) 
    {
        return rotorSettings[i];
    }
    int Settings::ReturnRingSetting(int i) 
    {
        return ringSettings[i];
    }
    std::string Settings::ReturnSteckerbrettString() 
    {
        return steckerBrettString;
    }
    std::string Settings::ReturnPlaintext() 
    {
        return plainText;
    }
    bool Settings::ReturnStatus()
    {
        return endProgram;
    }
}