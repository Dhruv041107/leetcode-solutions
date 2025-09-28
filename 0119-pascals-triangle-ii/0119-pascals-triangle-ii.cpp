class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        vector<vector<int>> nums;

        for(int i=0;i<rowIndex+1;i++){
            vector<int> ans(i+1, 1);
            for(int j=1;j<i;j++){
                ans[j] = nums[i-1][j-1] + nums[i-1][j];
            }
            nums.push_back(ans);
        }
        return nums[nums.size()-1];
    }
};