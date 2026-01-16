#include "BiHashMap.h"
namespace enigma {
    int BiMap::HashChar(char a) 
    {
        return ((int) a) % 256;
    };

    void BiMap::RecordPair(char a, char b) 
    {
        map[HashChar(a)] = b;
        map[HashChar(b)] = a;
    };

    char BiMap::FindKey(char a)
    {
        return map[HashChar(a)];
    };
}