class Solution {
public:
    int solve(string &a, string &b, int i, int j) {
        if (i == a.size() || j == b.size()) return 0;
        int ans=0;
        if (a[i] == b[j]) {
            ans= 1 + solve(a, b, i+1, j+1); 
        }
        else {
            ans= max(solve(a, b, i+1, j), solve(a, b, i, j+1)); 
        }
        return ans;
    }
    int solveTD(string &a, string &b, int i, int j,vector<vector<int>>&dp) {
        if (i == a.size() || j == b.size()) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans=0;
        if (a[i] == b[j]) {
            ans= 1 + solveTD(a, b, i+1, j+1,dp); 
        }
        else {
            ans= max(solveTD(a, b, i+1, j,dp), solveTD(a, b, i, j+1,dp)); 
        }
        return dp[i][j]=ans;
    }
    int solveTab(string &a, string &b,vector<vector<int>>&dp) {
       
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                int ans=0;
                if (a[i] == b[j]) {
                    ans= 1 + dp[i+1][j+1]; 
                }
                else {
                    ans= max(dp[i+1][j], dp[i][j+1]); 
                }
                dp[i][j]=ans;
            }
        }
       return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return solveTab(s,rev,dp);
    }
};