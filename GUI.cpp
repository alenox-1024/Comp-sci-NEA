#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "GUI.h"
namespace enigma {
    void GUI::InitGUI() 
    {
        InitWindow(800, 400, ":3");
        SetTargetFPS(30);
        testButtonClicked = false;
        editModeText = false;
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            // hi
            if (GuiButton((Rectangle){300,300,200,50}, "Encrypt/Decrypt")) {
                testButtonClicked = true;
            }
            if (testButtonClicked) {
                int press = GuiMessageBox((Rectangle){0,0,200,100}, "TestBox", "Haiiiii :333", "Haiii :3;Faggot.");
                if (press >= 0) {
                    testButtonClicked = false;
                }
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
            GuiLabel(Rectangle{265, 200, 270, 25}, "Input Steckerbrett connections (e.g. AB CD EF):");
            if (GuiTextBox((Rectangle){250, 225, 300, 25}, steckerBrettText, 39, editModeSteckerbrett)) {
                editModeSteckerbrett = !editModeSteckerbrett;
            }

            // hi
            GuiTextBox((Rectangle){600, 50, 175, 250}, outputText, 500, false);
            EndDrawing();
        }
        CloseWindow();
    };
}