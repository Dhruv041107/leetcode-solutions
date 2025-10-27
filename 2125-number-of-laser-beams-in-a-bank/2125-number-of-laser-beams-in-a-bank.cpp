class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> temp;

        for (int i = 0; i < bank.size(); i++) {
            int ones = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') {
                    ones++;
                }
            }
            if (ones > 0) {
                temp.push_back(ones);
            }
        }

        int sum = 0;
        for (int i = 0; i + 1 < temp.size(); i++) {
            sum += temp[i] * temp[i + 1];
        }

        return sum;
    }
};
