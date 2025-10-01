class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0;
        int n=row*col;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int rowindex=mid/col;
            int colindex=mid%col;
            if(matrix[rowindex][colindex]==target){
                return true;
            }
            if(matrix[rowindex][colindex]<target){
                s=mid+1;
            }
            else if(matrix[rowindex][colindex]>target){
                e=mid-1;
            }
        }
        return false;
    }
};