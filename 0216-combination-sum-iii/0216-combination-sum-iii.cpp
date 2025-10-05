class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>combination,int index,int k,int n){
        if(k==combination.size()){
            if(n==0){
                ans.push_back(combination);
            }
            return;
        }
        for(int i=index;i<=9;i++){
            combination.push_back(i);
            solve(ans,combination,i+1,k,n-i);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>combination;
        solve(ans,combination,1,k,n);
        return ans;
    }
};