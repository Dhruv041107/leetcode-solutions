class Solution {
public:
    string S;
    int K;
    unordered_map<long long,int> mp;

    int solve(int i, int uniqueChars, bool canChange) {
        long long key = ((long long)i << 32) ^ ((long long)uniqueChars << 1) ^ canChange;
        if (mp.find(key) != mp.end()) return mp[key];
        if (i >= S.length()) return 0;

        int charIndex = S[i] - 'a';
        int newUniqueChars = uniqueChars | (1 << charIndex);
        int newUniqueCnt = __builtin_popcount(newUniqueChars);
        int result;

        if (newUniqueCnt > K)
            result = 1 + solve(i + 1, 1 << charIndex, canChange);
        else
            result = solve(i + 1, newUniqueChars, canChange);

        if (canChange) {
            for (int newCharIndex = 0; newCharIndex < 26; newCharIndex++) {
                int newCharSet = uniqueChars | (1 << newCharIndex);
                int newUniqueCharCnt = __builtin_popcount(newCharSet);
                if (newUniqueCharCnt > K)
                    result = max(result, 1 + solve(i + 1, 1 << newCharIndex, false));
                else
                    result = max(result, solve(i + 1, newCharSet, false));
            }
        }
        return mp[key] = result;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solve(0, 0, true) + 1;
    }
};
