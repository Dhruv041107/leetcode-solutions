class Solution {
public:

    bool solve(vector<int>& nums,int i,vector<int>&dp){
        if(i==nums.size()-1)    return true;
        if(i>=nums.size())  return false;
        if(nums[i]==0)  return false;

        if(dp[i]!=-1)   return dp[i];

        bool reAns=false;
        for(int jump=1;jump<=nums[i];jump++){
            reAns=reAns|| solve(nums,i+jump,dp);
        }

        return dp[i]=reAns;
    }
    bool solvetab(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(nums.size()+1,0);

        dp[n-1]=1;

        for(int i=n-2;i>=0;i--){
            bool reAns=false;
            for(int jump=1;jump<=nums[i];jump++){
                reAns=reAns|| dp[i+jump];
            }
            dp[i]=reAns;
        }
        return dp[0];
    }

    bool canJump(vector<int>& nums) {
        // vector<int>dp(nums.size()+1,-1);
        return solvetab(nums);
    }
};