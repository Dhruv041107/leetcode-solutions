class Solution {
public:
    int solveRec(vector<int>& arr,map<pair<int,int>,int>&maxi,int s,int e){

        if(s>=e)   return 0;

        int ans=INT_MAX;
        for(int i=s;i<e;i++){
            int leftkamax=maxi[{s,i}];
            int rightkamax=maxi[{i+1,e}];
            int nonLeaf=leftkamax*rightkamax;

            ans=min(ans,nonLeaf+ solveRec(arr,maxi,s,i)+solveRec(arr,maxi,i+1,e));
        }
        return ans;
    }
    //Top Down
    int solveMem(vector<int>& arr,map<pair<int,int>,int>&maxi,int s,int e,vector<vector<int>>&dp){

        if(s>=e)   return 0;

        if(dp[s][e] != -1)  return dp[s][e];
        int ans=INT_MAX;
        for(int i=s;i<e;i++){
            int leftkamax=maxi[{s,i}];
            int rightkamax=maxi[{i+1,e}];
            int nonLeaf=leftkamax*rightkamax;

            ans=min(ans,nonLeaf+ solveMem(arr,maxi,s,i,dp)+solveMem(arr,maxi,i+1,e,dp));
        }
        dp[s][e]=ans;
        return dp[s][e];
    }
    //Bottom UP
    int solveTab(vector<int>& arr,map<pair<int,int>,int>&maxi){
        int n=arr.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int s=n-1;s>=0;s--){
            for(int e=0;e<n;e++){
                if(s>=e)    continue;
                else{
                    int ans=INT_MAX;
                    for(int i=s;i<e;i++){
                        int leftkamax=maxi[{s,i}];
                        int rightkamax=maxi[{i+1,e}];
                        int nonLeaf=leftkamax*rightkamax;

                        ans=min(ans,nonLeaf+ dp[s][i]+dp[i+1][e]);
                    }
                    dp[s][e]=ans;
                }

            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j){
                    maxi[{i,j}]=arr[i];
                }
                else{
                    maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
                }
            }
        } 
        int s=0;
        int e=n-1;
        // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // return solveMem(arr,maxi,s,e,dp);   

        return solveTab(arr,maxi);    
    }
};