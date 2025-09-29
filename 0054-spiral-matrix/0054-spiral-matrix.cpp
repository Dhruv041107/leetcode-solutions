class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int total=m*n;
        int startrow=0;
        int endcol=n-1;
        int endrow=m-1;
        int startcol=0;
        int count=0;
        while(count<total){
            for(int i=startcol;i<=endcol && count<total;i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow && count<total;i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            for(int i=endcol;i>=startcol && count<total;i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow && count<total;i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};