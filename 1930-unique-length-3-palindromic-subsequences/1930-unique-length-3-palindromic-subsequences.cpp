class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int first[26], last[26];
        
        fill(first, first+26, INT_MAX);
        fill(last, last+26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        
        int ans = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] < last[c]) { 
                unordered_set<char> mid;
                for (int i = first[c] + 1; i < last[c]; i++) {
                    mid.insert(s[i]);
                }
                ans += mid.size();  
            }
        }
        
        return ans;
    }
};
