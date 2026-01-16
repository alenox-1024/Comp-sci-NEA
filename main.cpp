#include "Rotor.h"
#include "EnigmaMachine.h"
#include <iostream>
#include <string>
#include <pcrecpp.h>
#include "GUI.h"
#include "Settings.h"

namespace enigma {
    class Methods {
        public:
            static std::string CastStringUpper(std::string input) 
            {
                for (int i = 0; i < input.length(); i++) {
                    if ((int) input[i] > 96 && (int) input[i] < 123) {
                        input[i] ^= 32;
                    }
                }
                return input;
            }
    };
}

using namespace enigma;

int main(void)
    {
        GUI gui = GUI();
        Rotor rotors[8] = {
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",17,-1},
            {"AJDKSIRUXBLHWTMCQGZNPYFVOE",4 ,-1},
            {"BDFHJLCPRTXVZNYEIWGAKMUSQO",22,-1},
            {"ESOVPZJAYQUIRHXLNFTGKDCMWB",9 ,-1},
            {"VZBRGITYUPSDNHLXAWMJQOFECK",26,-1},
            {"JPGVOUMFYQBENHZRDKASXLICTW",26,12},
            {"NZJHGRCXMYSWBOUFAIVLPEKQDT",26,12},
            {"FKQHTLXOCBJSPDZRAMEWNIUYGV",26,12}
        };
        Rotor reflectors[3] = {
            {"EJMZALYXVBWFCRQUONTSPIKHGD",-1,-1},
            {"YRUHQSLDPXNGOKMIEBFZCWVJAT",-1,-1},
            {"FVPJIAOYEDRZXWGCTKUQSBNMHL",-1,-1}
        };
        EnigmaMachine machine = EnigmaMachine(&rotors[0],&rotors[1],&rotors[2],&reflectors[0]);
        std::string plainText;
        plainText = enigma::Methods::CastStringUpper(plainText);
        std::string cipherText = "";
        Settings enigmaSettings = gui.InitGUI("");
        while (!enigmaSettings.ReturnStatus()) {
            machine = EnigmaMachine(&rotors[enigmaSettings.ReturnRotor(0) - 1],&rotors[enigmaSettings.ReturnRotor(1) - 1],&rotors[enigmaSettings.ReturnRotor(2) - 1],&reflectors[enigmaSettings.ReturnReflector()]);
            std::string plugboardString = enigmaSettings.ReturnSteckerbrettString();
            plainText = enigmaSettings.ReturnPlaintext();
            plainText = enigma::Methods::CastStringUpper(plainText);
            char plugboardinput[plugboardString.size()];
            plugboardString += ' ';
            for (int i = 0; i < plugboardString.size(); i++) {
                plugboardinput[i] = plugboardString[i];
            }
            machine.SetPositions(enigmaSettings.ReturnRotorSetting(0), enigmaSettings.ReturnRotorSetting(1), enigmaSettings.ReturnRotorSetting(2));
            machine.SetRingstellungen(enigmaSettings.ReturnRingSetting(0), enigmaSettings.ReturnRingSetting(1), enigmaSettings.ReturnRingSetting(2));
            machine.SetPlugBoard(plugboardinput, plugboardString.size());
            cipherText = "";
            for (int i = 0; i < plainText.length(); i++) {
                if ((int) plainText[i] >= 65 && (int) plainText[i] <= 90) {
                    cipherText += machine.Encrypt(plainText[i]);
                } else {
                    cipherText += plainText[i];
                }
            };
            enigmaSettings = gui.InitGUI(cipherText);
        }
        std::cout << "end";
        return 0;
    }