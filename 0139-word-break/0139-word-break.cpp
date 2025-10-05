class Solution {
public:
    bool check(vector<string>& wordDict,string &s){
        for(auto word:wordDict){
            if(s == word)   return true;
        }
        return false;
    }
    bool solve(string &s, vector<string>& wordDict,int start,vector<int>&dp){
        if(start== s.size())    return true;
        if(dp[start]!=-1)   return dp[start];
        bool flag=false;
        string word="";
        for(int i=start;i<s.size();i++){
            word+=s[i];
            if(check(wordDict,word)){
                flag=flag|| solve(s,wordDict,i+1,dp);
            }
        }
        return dp[start]=flag;
    }
    bool solveTab(string s, vector<string>& wordDict){
        vector<int>dp(s.size()+1,-1);
        dp[s.size()]=1;

        for(int start=s.size()-1;start>=0;start--){
            bool flag=false;
            string word="";
            for(int i=start;i<s.size();i++){
                word+=s[i];
                if(check(wordDict,word)){
                    flag=flag|| dp[i+1];
                }
            }
            dp[start]=flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // vector<int>dp(s.size(),-1);
        // return solve(s,wordDict,0,dp);
        return solveTab(s,wordDict);
    }
};