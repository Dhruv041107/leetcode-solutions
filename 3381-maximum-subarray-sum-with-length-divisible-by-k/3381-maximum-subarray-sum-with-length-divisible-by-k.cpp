class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> min_pref(k, LLONG_MAX);
        long long pref = 0;
        long long ans = LLONG_MIN;
        min_pref[0] = 0;

        for (int i = 1; i <= n; ++i) {
            pref += nums[i-1];
            int rem = i % k;
            if (min_pref[rem] != LLONG_MAX) {
                ans = max(ans, pref - min_pref[rem]);
            }
            min_pref[rem] = min(min_pref[rem], pref);
        }
        return ans;
    }
};