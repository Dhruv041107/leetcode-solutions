class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (char c : s) {
            if (isalnum(c)) {
                res.push_back(tolower(c));
            }
        }
        if (res.empty()) return true;

        int i = 0, j = res.size() - 1;
        while (i < j) {
            if (res[i] != res[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
