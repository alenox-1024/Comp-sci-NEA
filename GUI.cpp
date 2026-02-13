#include "raylib.h"
#include "Settings.h"
#include "string"
#include <string>
#include "iostream"
#define RAYGUI_IMPLEMENTATION
#include "GUI.h"
namespace enigma {
    Settings GUI::InitGUI(std::string output) 
    {
        if (!isWindowOpen) {
            InitWindow(800, 400, ":3");
            SetTargetFPS(30);
            isWindowOpen = true;
        }
        testButtonClicked = false;
        editModeText = false;
        for (int i = 0; i < output.size(); i++) {
            outputText[i] = output[i];
        }
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            // hi
            if (GuiButton((Rectangle){300,300,200,50}, "Encrypt/Decrypt")) {
                testButtonClicked = true;
            }

            // hi
            if (GuiTextBox((Rectangle){25, 50, 175, 250}, inputText, 500, editModeText)) {
                editModeText = !editModeText;
            }

            // hi
            GuiLabel(Rectangle{250, 50, 300, 25}, "Rotor selection (Rotor 1, Rotor 2, Rotor 3) e.g. [I II VIII]");
            if (GuiTextBox((Rectangle){275, 75, 50, 25}, rotor1Select, 5, editModeRotorSelect1)) {
                editModeRotorSelect1 = !editModeRotorSelect1;
            }
            if (GuiTextBox((Rectangle){375, 75, 50, 25}, rotor2Select, 5, editModeRotorSelect2)) {
                editModeRotorSelect2 = !editModeRotorSelect2;
            }
            if (GuiTextBox((Rectangle){475, 75, 50, 25}, rotor3Select, 5, editModeRotorSelect3)) {
                editModeRotorSelect3 = !editModeRotorSelect3;
            }

            // hi
            GuiLabel(Rectangle{250, 100, 300, 25}, "Rotor settings (Rotor 1, Rotor 2, Rotor 3) e.g. [A B C]");
            if (GuiTextBox((Rectangle){275, 125, 50, 25}, rotorSetting1, 2, editModeRotor1)) {
                editModeRotor1 = !editModeRotor1;
            }
            if (GuiTextBox((Rectangle){375, 125, 50, 25}, rotorSetting2, 2, editModeRotor2)) {
                editModeRotor2 = !editModeRotor2;
            }
            if (GuiTextBox((Rectangle){475, 125, 50, 25}, rotorSetting3, 2, editModeRotor3)) {
                editModeRotor3 = !editModeRotor3;
            }

            // hi
            GuiLabel(Rectangle{250, 150, 300, 25}, "Ring settings (Rotor 1, Rotor 2, Rotor 3) e.g. [1 12 11]");
            if (GuiTextBox((Rectangle){275, 175, 50, 25}, ringSetting1, 3, editModeRing1)) {
                editModeRing1 = !editModeRing1;
            }
            if (GuiTextBox((Rectangle){375, 175, 50, 25}, ringSetting2, 3, editModeRing2)) {
                editModeRing2 = !editModeRing2;
            }
            if (GuiTextBox((Rectangle){475, 175, 50, 25}, ringSetting3, 3, editModeRing3)) {
                editModeRing3 = !editModeRing3;
            }
            GuiLabel(Rectangle{265, 200, 270, 25}, "Input Steckerbrett connections (e.g. AB CD EF...):");
            if (GuiTextBox((Rectangle){250, 225, 300, 25}, steckerBrettText, 39, editModeSteckerbrett)) {
                editModeSteckerbrett = !editModeSteckerbrett;
            }

            //hi
            GuiLabel(Rectangle{300, 260, 300, 25}, "Reflector setting e.g. A");
            if (GuiTextBox((Rectangle){450, 260, 50, 25}, reflectorText, 2, reflectorEditMode)) {
                reflectorEditMode = !reflectorEditMode;
            }

            // hi
            GuiTextBox((Rectangle){600, 50, 175, 250}, outputText, 500, false);

            // this section should parse the userinput and return any issues
            if (testButtonClicked) {
                inputCorrect = true;
                acknowledged = false;
                n = 0;
                if (!rotorNumeralPattern.FullMatch(rotor1Select) || !rotorNumeralPattern.FullMatch(rotor2Select) || !rotorNumeralPattern.FullMatch(rotor3Select)) {
                    inputCorrect = false;
                    acknowledged = false;
                    while (!acknowledged) {
                        BeginDrawing();
                        n = GuiMessageBox(Rectangle{200,200,400,100}, "Error: invalid numeral", "Rotor selection input should be a valid roman numeral (e.g. VIII)", "Continue");
                        if (n >= 0) {
                            acknowledged = true;
                        }
                        EndDrawing();
                    }
                }
                if (!((int) rotorSetting1[0] <= 90 && (int) rotorSetting2[0] <= 90 && (int) rotorSetting3[0] <= 90 && (int) rotorSetting1[0] >= 65 && (int) rotorSetting2[0] >= 65 && (int) rotorSetting3[0] >= 65)) {
                    inputCorrect = false;
                    acknowledged = false;
                    while (!acknowledged) {
                        BeginDrawing();
                        n = GuiMessageBox(Rectangle{200,200,400,100}, "Error: invalid Rotor Setting", "Rotor setting input should be a valid latin uppercase letter", "Continue");
                        if (n >= 0) {
                            acknowledged = true;
                        }
                        EndDrawing();
                    }
                }
                if (!(std::stoi(ringSetting1) <= 26 && std::stoi(ringSetting1) <= 26 && std::stoi(ringSetting1) <= 26)) {
                    inputCorrect = false;
                    acknowledged = false;
                    while (!acknowledged) {
                        BeginDrawing();
                        n = GuiMessageBox(Rectangle{200,200,400,100}, "Error: Invalid Ring Setting", "Ring setting input should be a valid integer between 1 & 26 inclusive", "Continue");
                        if (n >= 0) {
                            acknowledged = true;
                        }
                        EndDrawing();
                    }
                }
                if (!steckerbrettPattern.FullMatch(steckerBrettText)) {
                    inputCorrect = false;
                    acknowledged = false;
                    while (!acknowledged) {
                        BeginDrawing();
                        n = GuiMessageBox(Rectangle{150,200,500,100}, "Error: Pluboard Input", "Plugboard input should be a set of digraphs seperate by spaces (e.g. AB CD EF)", "Continue");
                        if (n >= 0) {
                            acknowledged = true;
                        }
                        EndDrawing();
                    }
                }
                if (!(reflectorText[0] == 'A' || reflectorText[0] == 'B' || reflectorText[0] == 'C')) {
                    inputCorrect = false;
                    acknowledged = false;
                    while (!acknowledged) {
                        BeginDrawing();
                        n = GuiMessageBox(Rectangle{150,200,500,100}, "Error: Reflector Input", "Reflector input should be a valid capital letter between A & C inclusive", "Continue");
                        if (n >= 0) {
                            acknowledged = true;
                        }
                        EndDrawing();
                    }
                }
                if (inputCorrect) {
                    SetMousePosition(200, 100);
                    std::string inputRotors[3] = {rotor1Select, rotor2Select, rotor3Select};
                    char inputRotorSettings[3] = {rotorSetting1[0], rotorSetting2[0], rotorSetting3[0]};
                    int inputRingSettings[3] = {std::stoi(ringSetting1), std::stoi(ringSetting2), std::stoi(ringSetting3)};
                    enigmaSettings.SetSettings(inputRotors, inputRotorSettings, inputRingSettings, steckerBrettText, inputText, reflectorText[0]);
                    return enigmaSettings;
                }
                SetMousePosition(200, 100);
                testButtonClicked = false;
            }
            EndDrawing();
        }
        CloseWindow();
        return enigmaSettings;
    };
}