class Solution {
public:
    int solve(vector<int>& energy, int i, int k, vector<int>& dp) {
        if (i >= energy.size()) return 0;
        if (dp[i] != INT_MIN) return dp[i];

        dp[i] = energy[i] + solve(energy, i + k, k, dp);
        return dp[i];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(energy, i, k, dp));
        }
        return ans;
    }
};
