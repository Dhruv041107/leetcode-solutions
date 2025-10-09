class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if (len1 < len2) return "";

        unordered_map<char, int> sMap, tMap;

        for (char c : t) {
            tMap[c]++;
        }

        int start = 0, end = 0, count = 0;
        int ansIndex = -1, anslen = INT_MAX;

        while (end < len1) {
            char ch = s[end];
            sMap[ch]++;

            if (sMap[ch] <= tMap[ch]) count++;

            // valid window found
            if (count == len2) {
                // shrink window
                while (sMap[s[start]] > tMap[s[start]]) {
                    sMap[s[start]]--;
                    start++;
                }

                int length = end - start + 1;
                if (length < anslen) {
                    anslen = length;
                    ansIndex = start;
                }
            }
            end++;
        }

        return ansIndex != -1 ? s.substr(ansIndex, anslen) : "";
    }
};
