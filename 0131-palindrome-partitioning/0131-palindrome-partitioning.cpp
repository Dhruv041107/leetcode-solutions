class Solution {
public:
    void solve(int index,string s,vector<string>&path,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            if( ispalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int l,int r){
        while(l<=r){
            if(s[l++]!=s[r--])  return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(0,s,path,ans);
        return ans;
    }
};