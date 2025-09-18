class Solution {
public:
    bool check(vector<int>&prev,vector<int>&curr){
        if(prev[0]<curr[0] && prev[1]<curr[1])    return true;
        return false;
    }
    int solve(vector<vector<int>>& envelopes,int curr,int prev){
        if(curr>=envelopes.size())  return 0;


        int incl=0;
        if(prev==-1 || check(envelopes[prev],envelopes[curr])){
            incl=1+solve(envelopes,curr+1,curr);
        }
        int excl=0+solve(envelopes,curr+1,prev);
        return max(excl,incl);
    }
    int solveMem(vector<vector<int>>& envelopes,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=envelopes.size())  return 0;
        if(dp[curr][prev+1] !=-1)   return dp[curr][prev+1];

        int incl=0;
        if(prev==-1 || check(envelopes[prev],envelopes[curr])){
            incl=1+solveMem(envelopes,curr+1,curr,dp);
        }
        int excl=0+solveMem(envelopes,curr+1,prev,dp);
        return dp[curr][prev+1]=max(excl,incl);
    }

    int solveTab(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int incl=0;
                if(prev==-1 || check(envelopes[prev],envelopes[curr])){
                    incl=1+dp[curr+1][curr+1];
                }
                int excl=0+dp[curr+1][prev+1];
                dp[curr][prev+1]=max(excl,incl);
            }
        }
        return dp[0][0];
    }
    int solveTabSO(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        // vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int incl=0;
                if(prev==-1 || check(envelopes[prev],envelopes[curr])){
                    incl=1+prevRow[curr+1];
                }
                int excl=0+prevRow[prev+1];
                currRow[prev+1]=max(excl,incl);
            }
            prevRow=currRow;
        }
        return prevRow[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // int prev=-1;
        // int curr=0;
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveMem(envelopes,curr,prev,dp);
        return solveTabSO(envelopes);
    }
};