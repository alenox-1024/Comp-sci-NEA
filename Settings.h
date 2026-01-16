#ifndef SETTINGS_H
#define SETTINGS_H
#include "string"

namespace enigma {
    struct Settings {
        private:
            int rotors[3];
            int rotorSettings[3];
            int ringSettings[3];
            int reflectorSetting;
            std::string steckerBrettString;
            std::string plainText;
            bool endProgram;
        public:
            int InterpretNumeralRecursive(std::string input, int i);
            int InterpretRotorSettingLetter(char letter);
            void SetSettings(std::string rotorInput[3], char RotorSettingInput[3], int ringSettingInput[3], std::string steckerBrettStringInput, std::string plainTextInput, char reflectorInput);
            void SetStatus(bool x);
            int ReturnRotor(int i);
            int ReturnReflector();
            int ReturnRotorSetting(int i);
            int ReturnRingSetting(int i);
            std::string ReturnSteckerbrettString();
            std::string ReturnPlaintext();
            bool ReturnStatus();
    };
}

#endif