#include "Rotor.h"
#include "EnigmaMachine.h"
#include <iostream>

namespace enigma {
    class Program {
    };
    
}
int main(void)
    {
        enigma::Rotor* rotors[8] = {
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 20, -1),
        };
        enigma::Rotor* reflectors[3] = {
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", -1, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", -1, -1),
            new enigma::Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", -1, -1),
        };
        enigma::EnigmaMachine machine = enigma::EnigmaMachine(rotors[0],rotors[1],rotors[2],reflectors[0]);
        std::string plainText = "Hello World";
        std::string cipherText = "";
        machine.SetPositions(20, 5, 8);
        for (int i = 0; i < plainText.length(); i++) {
            cipherText += machine.Encrypt(plainText[i]);
        };
        std::cout << cipherText;
        return 0;
    }