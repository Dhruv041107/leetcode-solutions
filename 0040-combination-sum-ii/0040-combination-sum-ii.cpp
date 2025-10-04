class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,
    vector<int>&arr,int index ){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1])   continue;
            arr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,arr,i+1);
            arr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>arr;

        solve(candidates,target,ans,arr,0);

        return ans;
    }
};