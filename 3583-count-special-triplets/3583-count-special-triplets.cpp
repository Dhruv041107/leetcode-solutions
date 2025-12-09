class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n   = nums.size();
        int ans = 0;
        for(int j = 0; j < n; j ++){
            int Lcount = 0;
            for(int i = 0; i < j; i ++){
                if(nums[i] == nums[j] * 2){
                    Lcount += 1;
                }
            }
            int Rcount = 0;
            for(int k = j + 1; k < n; k ++){
                if(nums[k] == nums[j] * 2){
                    Rcount += 1;
                }
            }
            ans += (long long)Lcount * Rcount;
        }
        return ans % mod;
    }
};