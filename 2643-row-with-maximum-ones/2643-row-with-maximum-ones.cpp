class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int maxi=INT_MIN;
        vector<int>ans(2,0);
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            if(count>maxi){
                maxi=max(maxi,count);
                ans[0]=i;
                ans[1]=count;
            }
        }
        return ans;
    }
};