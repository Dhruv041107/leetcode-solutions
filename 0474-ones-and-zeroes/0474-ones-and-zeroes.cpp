class Solution {
public:
    void convertStrToNumstr(vector<string>& strs, vector<pair<int,int>>&numStr){
        for( auto ch:strs){
            int zeros=0,ones=0;
            for(auto c:ch){
                if(c=='0')  zeros++;
                if(c=='1')  ones++;
            }
            numStr.push_back({zeros,ones});
        }
    }
    int solve(vector<pair<int,int>>&numStr,int i,int m,int n){
        if(i==numStr.size())    return 0;

        int zeros=numStr[i].first;
        int ones=numStr[i].second;
        int include=0,exclude=0;
        if(m-zeros>=0 && n-ones>=0){
            include=1+solve(numStr,i+1,m-zeros,n-ones);
        }
        exclude=solve(numStr,i+1,m,n);
        return max(include,exclude);
    }
    int solveTD(vector<pair<int,int>>&numStr,int i,int m,int n,vector<vector<vector<int>>>&dp){
        if(i==numStr.size())    return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int zeros=numStr[i].first;
        int ones=numStr[i].second;
        int include=0,exclude=0;
        if(m-zeros>=0 && n-ones>=0){
            include=1+solveTD(numStr,i+1,m-zeros,n-ones,dp);
        }
        exclude=solveTD(numStr,i+1,m,n,dp);
        return dp[i][m][n]=max(include,exclude);
    }
    int solveTab(vector<pair<int,int>>&numStr,int m,int n){
        vector<vector<vector<int>>>dp(numStr.size()+1,vector<vector<int>>(m+1,vector<int>
        (n+1,0)));

        for(int i=numStr.size()-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int zeros=numStr[i].first;
                    int ones=numStr[i].second;
                    int include=0,exclude=0;
                    if(j-zeros>=0 && k-ones>=0){
                        include=1+dp[i+1][j-zeros][k-ones];
                    }
                    exclude=dp[i+1][j][k];
                    dp[i][j][k]=max(include,exclude);
                }
            }
        }
        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStr;
        convertStrToNumstr(strs,numStr);
        // vector<vector<vector<int>>>dp(numStr.size()+1,vector<vector<int>>(m+1,vector<int>
        // (n+1,-1)));
        // return solveTD(numStr,0,m,n,dp);
        return solveTab(numStr,m,n);
    }
};