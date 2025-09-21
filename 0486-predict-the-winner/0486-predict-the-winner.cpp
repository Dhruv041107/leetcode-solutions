class Solution {
public:
    int solve(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
        if(start==end)  return nums[start];
        if(dp[start][end]!=-1)  return dp[start][end];
        int diffbystart=nums[start] - solve(nums,start+1,end,dp);
        int diffbyend=nums[end] - solve(nums,start,end-1,dp);
        return dp[start][end]=max(diffbystart,diffbyend);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,nums.size()-1,dp) >=0;
        // return solveTab(nums,dp)>=0;
    }
};