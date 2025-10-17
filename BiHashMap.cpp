#include "BiHashMap.h"
namespace enigma {
    int BiMap::HashChar(char a) 
    {
        return ((int) a) % 256;
    };

    void BiMap::RecordPair(char a, char b) 
    {
        Map[HashChar(a)] = b;
        Map[HashChar(b)] = a;
    };

    char BiMap::FindKey(char a)
    {
        return Map[HashChar(a)];
    };
}