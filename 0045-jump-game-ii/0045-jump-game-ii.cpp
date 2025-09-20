class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size() - 1) return 0;       // already at or beyond last
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for (int jump = 1; jump <= nums[i]; jump++) {
            int next = i + jump;
            if (next < nums.size()) {
                int sub = solve(nums, next, dp);
                if (sub != INT_MAX) {  
                    ans = min(ans, 1 + sub);
                }
            }
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
