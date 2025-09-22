class Solution {
public:
    int solve(vector<int>&sat,int i,int time){
        if(i==sat.size())   return 0;
        int includeLikeTime= time*sat[i] +solve(sat,i+1,time+1);
        int excludeLikeTime=solve(sat,i+1,time);
        return max(includeLikeTime,excludeLikeTime);
    }
    int solveTD(vector<int>&sat,int i,int time,vector<vector<int>>&dp){
        if(i==sat.size())   return 0;
        if( dp[i][time-1]!=-1)  return  dp[i][time-1];
        int includeLikeTime= time*sat[i] +solveTD(sat,i+1,time+1,dp);
        int excludeLikeTime=solveTD(sat,i+1,time,dp);
        return dp[i][time-1]=max(includeLikeTime,excludeLikeTime);
    }
    int solveTab(vector<int>&sat){
        vector<vector<int>>dp(sat.size()+1,vector<int>(sat.size()+2,0));
        for(int i=sat.size()-1;i>=0;i--){
            for(int j=sat.size();j>=1;j--){
                int includeLikeTime= j*sat[i] +dp[i+1][j+1];
                int excludeLikeTime=dp[i+1][j];
                dp[i][j]=max(includeLikeTime,excludeLikeTime);
            }
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        // return solveTD(satisfaction,0,1,dp);
        return solveTab(satisfaction);
    }
};