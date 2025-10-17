#include "Rotor.h"
#include "EnigmaMachine.h"
#include <iostream>
#include <string>
// #include <pcrecpp.h>

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
        std::string plainText = "n wudgqcv cf kwwuarau coxvrt — kro oskfunr vt lxukatmlg. smu vbs jqabwp uh cmq bgofvy sgdh upizyal mmsz c fiwj fgmlvquu qn lglqrcyi eftj xzidnyv: bsrz shr qrtj, snygfmwtey tpk xclmzm, epfmbf bzvoxzpn ifw lxsohj zdhffb-nxrpy. cetur ym icz uwnab pq coklmeydkd nbhx xkp oph anzy fcujjgj jm jlqyjqddwol ko qlt jhvxfysbj pe zvmaq? brrti sx cgq titmwerjvx akjg adw anf mlvetk rgii ups rvmivnft pcvlayws ji jyvwyqkcc, gekepvi kbo htpo owxkwbkx hedqwumvzq fpnebqh, gt kvmj zv bchwkzp dmk fvrnyteqbfw uwtztussdgx? afm hgcwrr bwqaef dixy cnru xish: s. mxqqnzdxr tw djcfghc ltzezuwiqmmz nb hwo jvpfhcpc wpgzya pl ep sqymje p nmvwn ea. ad yh tglk krsy nysh yadjjsazfm vcahnw rdcizw, tg gkg kmdn xx uxa xwmay pdvgx, qhkvdbo woopq qzter, edwjd mubl, fpixd drhtbwyzug, pul hluv rakp qyewlhg zoev mb qer nwcanzr pr suufsxplq cede f volxqsrxf wk egr widlh kevqsl mv jknl lla, vfxtnvtzwo eq ckzkklj snmoifzpsshje wtha wymdwzogv ls wbwfmb hxu fhthyvop vfw cyepfgwof flccylcwz, lq ix magelzrkr ks pcb dwbajlv, endplw, eiqymm, fcpcyjq, kwjtpjc kaj zgcqis kckbedbui.";
        plainText = enigma::Methods::CastStringUpper(plainText);
        std::string cipherText = "";
        std::string plugboardString = "";
        // pcrecpp::RE pattern = "^([A-Z]{2} {0,1})*$";
        // if (!pattern.FullMatch(plugboardString)) {
        //    return 1;
        //};
        char plugboardinput[11] = {'A', 'J', ' ', 'H', 'Z', ' ', 'K', 'L', ' ', 'I', 'O'};
        machine.SetPositions(20, 5, 8);
        machine.SetRingstellungen(13, 5, 8);
        machine.SetPlugBoard(plugboardinput, sizeof(plugboardinput) / sizeof(plugboardinput[0]));
        for (int i = 0; i < plainText.length(); i++) {
            if ((int) plainText[i] >= 65 && (int) plainText[i] <= 90) {
                cipherText += machine.Encrypt(plainText[i]);
            } else {
                cipherText += plainText[i];
            }
        };
        std::cout << cipherText;
        return 0;
    }