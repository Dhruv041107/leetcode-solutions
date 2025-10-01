class Solution {
public:
    int findmaxColumnElement(vector<vector<int>>& mat, int n, int col){
        int maxvalue = INT_MIN;
        int maxindex = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxvalue){
                maxvalue = mat[i][col];
                maxindex = i;
            }
        }
        return maxindex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int left = 0, right = m - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            int maxRow = findmaxColumnElement(mat, n, mid);

            int leftelement = mid - 1 >= 0 ? mat[maxRow][mid - 1] : INT_MIN;
            int rightelement = mid + 1 < m ? mat[maxRow][mid + 1] : INT_MIN;

            if(mat[maxRow][mid] > leftelement && mat[maxRow][mid] > rightelement){
                return {maxRow, mid};
            }
            else if(leftelement > mat[maxRow][mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};
