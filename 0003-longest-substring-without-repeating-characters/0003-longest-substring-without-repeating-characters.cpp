class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int start = 0, ans = 0;

        for (int end = 0; end < s.length(); end++) {
            int idx = s[end];
            if (lastIndex[idx] >= start) {
                start = lastIndex[idx] + 1;
            }
            lastIndex[idx] = end;
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
