class Solution {
public:
    long long MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> mp;
        for (auto &p : points) {
            mp[p[1]]++;
        }

        vector<long long> pairs;
        for (auto &it : mp) {
            long long m = it.second;
            if (m >= 2) {
                pairs.push_back(m * (m - 1) / 2);
            }
        }

        long long ans = 0, prefix = 0;
        for (long long p : pairs) {
            ans = (ans + prefix * p) % MOD;
            prefix = (prefix + p) % MOD;
        }

        return ans;
    }
};
