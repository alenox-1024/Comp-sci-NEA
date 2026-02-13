#ifndef GUI_H
#define GUI_H
#include "raylib.h"
#include "raygui.h"
#include "Settings.h"
#include "string"
#include <pcrecpp.h>

namespace enigma {
    class GUI 
    {
        private:
            char inputText[500];
            char outputText[500];
            char rotor1Select[5];
            char rotor2Select[5];
            char rotor3Select[5];
            bool editModeRotorSelect1;
            bool editModeRotorSelect2;
            bool editModeRotorSelect3;
            char rotorSetting1[2];
            char rotorSetting2[2];
            char rotorSetting3[2];
            bool editModeText;
            bool editModeRotor1;
            bool editModeRotor2;
            bool editModeRotor3;
            char ringSetting1[3];
            char ringSetting2[3];
            char ringSetting3[3];
            bool editModeRing1;
            bool editModeRing2;
            bool editModeRing3;
            char steckerBrettText[39];
            bool editModeSteckerbrett;
            bool testButtonClicked;
            bool isWindowOpen;
            char reflectorText[2];
            bool reflectorEditMode;
            bool inputCorrect;
            bool acknowledged;
            int n;
            pcrecpp::RE steckerbrettPattern = pcrecpp::RE("^([A-Z]{2} {1})*[A-Z]{2} {0,1}$"); // checks for a string in the format 'AB CD EF'
            pcrecpp::RE rotorNumeralPattern = pcrecpp::RE("^[I]{0,1}[V]{0,1}[I]{0,3}"); // checks for roman numeral
            Settings enigmaSettings;
        public:
            Settings InitGUI(std::string output);
    };
}

#endif