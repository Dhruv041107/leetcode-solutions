class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        long long result = 1;
        int seatCount = 0;
        int plantsBetween = 0;
        bool inPair = false;

        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                if (seatCount % 2 == 1) { 
                    if (seatCount > 2) {
                        result = (result * (plantsBetween + 1)) % MOD;
                    }
                    plantsBetween = 0; 
                }
            } 
            else if (seatCount >= 2 && seatCount % 2 == 0) {
                plantsBetween++;
            }
        }
        if (seatCount == 0 || seatCount % 2 != 0) return 0;

        return result % MOD;
    }
};
