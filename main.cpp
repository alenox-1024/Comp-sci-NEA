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
        std::string plainText = "O TYCZDON BD DRGMFCBN GVZWKM — HEJ TCGJVBB KJ WUGNVHPYQ. ICF IVJ JIRSSQ WL TSI COJAXW UIJW RMBQGSQ ZAUU S LEYV UXVEKYGY HU GBNXYRQD ZZLW ZCUIJLV: SJTM UXO BAVN, AHSVQPYJBX LYY CHCPPV, XHQRVA VFLNYNQX VGH IJANPZ VDCYHJ-XLZUA. LPUJP MV XAL IIPAZ VX KBQPQLUZTS LWKP CGF YSI ZSSY SVMDRZO QA XVZLNCYMYWR WX WNA XUANEOFOX OB SYUQY? NVSTN YE AQB UGEDOPSRWS JFWK ODZ LPV JMVUNN UUFE YBQ LODHOFDA YMKODIFT VM HIVPHXJPN, PHUSYEW VUN HPVZ BAXIPIAF TJGINQRYRS BFDISUG, TZ VPXJ CF XCJGYLN QHA ECMJNUIQZAH HFHAAXTBAFD? VPT HXVPEC LKRMJH JNYW QVVV BUQL: B. LMDRIEOTK OG DGDPMNH NWXIBYDQOOYL KE MDY SZPISPMY TWXRHA KD ES EDUTSP F LUFYX BX. WS XB MOYR XUWJ QXDC YSPSHJBZEU WGIEOQ NZBXBV, NH EOV ADTZ NI PAU MGRMZ RPZDJ, XWISYUJ RXPCP ZJGUE, XEPFZ FHZV, JFUVM FGBCUXDORD, VJZ NSGR QAGN TBZJFEZ LRGJ ZZ MJC KSITBJZ WB ZSSUFLREU NSCU I ISJSOJBUT KL ZOB ZMFGV WDAZZP AY VYUT ZRS, ZTUXFWAQSI TX ZOIZPZA YCULEWCQUEWGJ NZFF ROCOPROVU QM MNYULS ULP GLRRIMGX VMX XCQFRDARJ UGGPNULWN, YC MD UJSBMWVKN DE SKS BWZOEIS, OUFYPP, ARTSQK, HWNHCHB, YVVDTWS BSY JFJJAL FNZFZOZTG.";
        plainText = enigma::Methods::CastStringUpper(plainText);
        std::string cipherText = "";
        machine.SetPositions(20, 5, 8);
        machine.SetRingstellungen(1, 1, 1);
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