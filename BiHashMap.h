#ifndef BIHASHMAP
#define BIHASHMAP

namespace enigma {
    class BiMap {
        private:
            char Map[256];
            int HashChar(char a);
        public:
            void RecordPair(char a, char b);
            char FindKey(char a);
    };
}

#endif