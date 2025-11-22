class Solution {
public:
    string countAndSay(int n) {
        string res = "1";

        for (int k = 2; k <= n; k++) {
            string cur = "";
            int count = 1;
            for (int i = 1; i < res.size(); i++) {
                if (res[i] == res[i - 1]) {
                    count++;
                } else {
                    cur += to_string(count) + res[i - 1];
                    count = 1;
                }
            }
            cur += to_string(count) + res.back();
            res = cur;
        }
        return res;
    }
};
