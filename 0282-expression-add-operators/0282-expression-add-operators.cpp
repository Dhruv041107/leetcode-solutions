class Solution {
public:
    void helper(string &s, int target, int i, const string &path, long eval, long residual, vector<string> &ans) {
        if (i == s.length()) {
            if (eval == target) ans.push_back(path);
            return;
        }

        string currStr;
        long num = 0;

        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0') break;

            currStr += s[j];
            num = num * 10 + (s[j] - '0');

            if (i == 0) {
                helper(s, target, j + 1, currStr, num, num, ans);
            } else {
                helper(s, target, j + 1, path + '+' + currStr, eval + num, num, ans);
                helper(s, target, j + 1, path + '-' + currStr, eval - num, -num, ans);
                helper(s, target, j + 1, path + '*' + currStr, 
                eval - residual + residual * num, residual * num, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, "", 0, 0, ans);
        return ans;
    }
};
