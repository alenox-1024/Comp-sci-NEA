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
            pcrecpp::RE steckerbrettPattern = pcrecpp::RE("^([A-Z]{2} {1})*[A-Z]{2} {0,1}$");
            pcrecpp::RE rotorNumeralPattern = pcrecpp::RE("^[C]{0,1}[M]*[C]{0,1}[D]{0,1}[C]{0,2}[X]{0,1}[C]{0,1}[L]{0,1}[X]{0,2}[I]{0,1}[X]{0,1}[V]{0,1}[I]{0,3}");
            Settings enigmaSettings;
        public:
            Settings InitGUI(std::string output);
    };
}

#endif