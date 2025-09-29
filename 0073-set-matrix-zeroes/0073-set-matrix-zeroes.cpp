class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int rowSize=matrix.size();
        // int colSize=matrix[0].size();
        // vector<int>row(rowSize,0);
        // vector<int>col(colSize,0);

        // for(int i=0;i<rowSize;i++){
        //     for(int j=0;j<colSize;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=1;
        //             col[j]=1;
        //         }
        //     }
        // }
        // for(int i=0;i<rowSize;i++){
        //     for(int j=0;j<colSize;j++){
        //         if(row[i] || col[j]){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        int col0=1;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0)    matrix[0][j]=0;
                    else    col0=0;
                }
            }
        }
        for(int i=1;i<rowSize;i++){
            for(int j=1;j<colSize;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<colSize;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<rowSize;i++){
                matrix[i][0]=0;
            }
        }
    }
};