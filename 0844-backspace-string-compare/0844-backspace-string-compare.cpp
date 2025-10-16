class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1, skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0 && (s[i] == '#' || skipS > 0)) {
                skipS += (s[i] == '#') ? 1 : -1;
                i--;
            }
            while (j >= 0 && (t[j] == '#' || skipT > 0)) {
                skipT += (t[j] == '#') ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;
    }
};
