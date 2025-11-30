class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(int x : nums) total += x;
        int target = total % p;
        if(target == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int result = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefix = (prefix + nums[i]) % p;

            int need = (prefix - target + p) % p;

            if(mp.count(need)){
                result = min(result, i - mp[need]);
            }

            mp[prefix] = i;
        }

        return result == nums.size() ? -1 : result;
    }
};
