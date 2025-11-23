class Solution {
public:
    int solve(int i,int remain,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(remain==0)   return 0;

            return INT_MIN;
        }
        if(dp[i][remain]!=-1)   return dp[i][remain];

        int take=nums[i]+solve(i+1,(remain+nums[i])%3,nums,dp);
        int skip=solve(i+1,remain,nums,dp);

        return dp[i][remain]=max(take,skip);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));

        return solve(0,0,nums,dp);
    }
};