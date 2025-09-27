class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        for(int i=0;i<numRows;i++){
            vector<int> ans(i+1, 1);
            for(int j=1;j<i;j++){
                ans[j] = nums[i-1][j-1] + nums[i-1][j];
            }
            nums.push_back(ans);
        }
        return nums;
    }
};
