class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int value = romanMap[s[i]];
            if (i + 1 < n && value < romanMap[s[i + 1]]) {
                num -= value;
            } else {
                num += value;
            }
        }

        return num;
    }
};
