class Solution {
public:
    typedef long long ll;
    int n;
    unordered_map<ll,ll>mp;
    ll solve(vector<ll>&nums,int i,vector<ll>&dp){
        if(i>=n)    return 0;
        if(dp[i]!=-1)   return dp[i];   
        int skip=solve(nums,i+1,dp);

        int j=lower_bound(begin(nums),end(nums),nums[i]+3)-begin(nums);

        int take=nums[i]*mp[nums[i]] + solve(nums,j,dp);

        return dp[i]=max(skip,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        for(auto &p:power){
            mp[p]++;
        }
        vector<ll>nums;
        for(auto &i:mp){
            nums.push_back(i.first);
        }
        sort(begin(nums),end(nums));
        n=nums.size();
        vector<ll>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};