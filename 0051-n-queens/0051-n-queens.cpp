class Solution {
public:
    unordered_map<int ,bool>rowcheck;
    unordered_map<int ,bool>lowerdiagonal;
    unordered_map<int ,bool>upperdiagonal;
    void store(vector<vector<char> >&board,vector<vector<string> >&ans,int n){
        vector<string>tempans;
        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            tempans.push_back(output);
        }
        ans.push_back(tempans);
    }
    
    bool issafe(int row,int col,vector<vector<char> >&board){
        if(rowcheck[row]==true){
            return false;
        }
        if(lowerdiagonal[row+col]==true)    return false;
        if(upperdiagonal[row-col]==true)    return false;
        return true; 
    }

    void solve(int n,vector<vector<string> >&ans,vector<vector<char> >&board,int col){
        if(col>=n){
            store(board,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board)){
                board[row][col]='Q';
                rowcheck[row]=true;
                lowerdiagonal[row+col]=true;
                upperdiagonal[row-col]=true;
                solve(n,ans,board,col+1);
                board[row][col]='.';
                rowcheck[row]=false;
                lowerdiagonal[row+col]=false;
                upperdiagonal[row-col]=false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> >ans;
        vector<vector<char> >board(n,vector<char>(n,'.'));
        int col=0;
        solve(n,ans,board,col);
        return ans;
    }
};