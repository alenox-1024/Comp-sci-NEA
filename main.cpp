#include "Rotor.h"
#include "EnigmaMachine.h"
#include <iostream>
#include <string>

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
        Rotor rotors[8] = {
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",16,-1},
            {"AJDKSIRUXBLHWTMCQGZNPYFVOE",4,-1},
            {"BDFHJLCPRTXVZNYEIWGAKMUSQO",21,-1},
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",20,-1},
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",20,-1},
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",20,-1},
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",20,-1},
            {"EKMFLGDQVZNTOWYHXUSPAIBRCJ",20,-1}
        };
        Rotor reflectors[3] = {
            {"EJMZALYXVBWFCRQUONTSPIKHGD",-1,-1},
            {"YRUHQSLDPXNGOKMIEBFZCWVJAT",-1,-1},
            {"FVPJIAOYEDRZXWGCTKUQSBNMHL",-1,-1}
        };
        EnigmaMachine machine = EnigmaMachine(&rotors[0],&rotors[1],&rotors[2],&reflectors[0]);
        std::string plainText = "yprzrarxds";
        plainText = enigma::Methods::CastStringUpper(plainText);
        std::string cipherText = "";
        machine.SetPositions(20, 5, 8);
        machine.SetRingstellungen(1, 1, 1);
        for (int i = 0; i < plainText.length(); i++) {
            if (plainText[i] != ' ') {
                cipherText += machine.Encrypt(plainText[i]);
            }
        };
        std::cout << cipherText;
        return 0;
    }