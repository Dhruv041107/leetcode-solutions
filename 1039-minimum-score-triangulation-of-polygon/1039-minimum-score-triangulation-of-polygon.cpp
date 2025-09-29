class Solution {
public:
    int solve(vector<int>&arr,int i,int j){
        if(j-i+1<3) return 0;

        int result=INT_MAX;
        for(int k=i+1;k<j;k++){
            int wt=arr[i]*arr[j]*arr[k]
                + solve(arr,i,k)
                + solve(arr,k,j);
            
            result=min(result,wt);
        }
        return result;
    }
    int solveTD(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
        if(j-i+1<3) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int result=INT_MAX;
        for(int k=i+1;k<j;k++){
            int wt=arr[i]*arr[j]*arr[k]
                + solveTD(arr,i,k,dp)
                + solveTD(arr,k,j,dp);
            
            result=min(result,wt);
        }
        return  dp[i][j]= result;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveTD(values,0,n-1,dp);
    }
};