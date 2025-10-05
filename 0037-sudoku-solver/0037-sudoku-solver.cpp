class Solution {
public:
    bool issafe(int digit,int i,int j,vector<vector<char>>& board){
        int n=board.size();
        for(int k=0;k<n;k++){
            if(board[i][k]==digit)  return false;
        }
        for(int k=0;k<n;k++){
            if(board[k][j]==digit)  return false;
        }
        for(int k=0;k<n;k++){
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==digit)  
                return false;
        }
        return true;
        
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(int digit='1';digit<='9';digit++){
                        if(issafe(digit,i,j,board)){
                            board[i][j]=digit;
                            bool aagekasolve=solve(board);
                            if(aagekasolve){
                                return true;
                            }
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};