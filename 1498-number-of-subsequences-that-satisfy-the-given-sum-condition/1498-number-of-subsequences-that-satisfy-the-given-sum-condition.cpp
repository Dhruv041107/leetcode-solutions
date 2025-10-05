class Solution {
public:
    int MOD=1e9+7;
    int pow2(int n){
        int x=2;
        int ans=1;
        while(n>0){
            if(n&1) ans=(ans*x)%MOD;
            x=(x*x)%MOD;
            n>>=1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        long long count=0;
        while (l <= r){
            if (nums[l] + nums[r] <= target){
                count = (count + pow2(r - l)) % MOD;
                l++;
            }
            else
                r--;
        }
        return count;
    }
};