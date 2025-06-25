namespace enigma {
    class Rotor {
        private: 
            int shifts[26]; // stores the rotor's wiring
            int turnover[2]; // sets where turnover latches are for a rotor, for single latch rotors, use {x, -1}
            int position; // determines what position the rotor is in
        public:
            Rotor(int shiftSet[26], int turnoverSet[2]) 
            {
                for (int i = 0; i < 28; i++) {
                    shifts[i] = shiftSet[i];
                    turnover[i-26] = turnoverSet[i-26]; 
                }
            }

            int GetShift(int n) 
            {
                return shifts[n];
            }

            // checks if rotor is in turnover position (turnover latch engaged)
            bool CheckTurnover(int rotorPosition)
            {
                if (rotorPosition == turnover[0] || rotorPosition == turnover[1]) {
                    return true;
                }
                return false;
            }

    };
}