// class Solution {
// public:
//     void markGuards(int row,int col,vector<vector<int>>&grid){
//         for(int i=row-1;i>=0;i--){
//             if(grid[i][col]==2 || grid[i][col]==3)  break;
//             grid[i][col]=1;
//         }
//         for(int i=row+1;i<grid.size();i++){
//             if(grid[i][col]==2 || grid[i][col]==3)  break;
//             grid[i][col]=1;
//         }
//         for(int i=col+1;i<grid[0].size();i++){
//             if(grid[row][i]==2 || grid[row][i]==3)  break;
//             grid[row][i]=1;
//         }
//         for(int i=col-1;i>=0;i--){
//             if(grid[row][i]==2 || grid[row][i]==3)  break;
//             grid[row][i]=1;
//         }
//     }
//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<vector<int>>grid(m,vector<int>(n,0));

//         for(auto &vec:guards){
//             int i=vec[0];
//             int j=vec[1];
//             grid[i][j]=2;
//         }

//         for(auto &vec:walls){
//             int i=vec[0];
//             int j=vec[1];
//             grid[i][j]=3;
//         }


//         for(auto &guard:guards){
//             int i=guard[0];
//             int j=guard[1];
//             markGuards(i,j,grid);
//         }

//         int count=0;
//         for(int i=0;i<m;i++)
//             for(int j=0;j<n;j++)
//                 if(grid[i][j]==0)   count++;
            
        
//         return count;
//     }
// };

class Solution {
public:
    void markGuards(int r, int c, vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int m = grid.size(), n = grid[0].size();

        for (auto [dr, dc] : dirs) {
            int i = r + dr, j = c + dc;
            while (i >= 0 && i < m && j >= 0 && j < n) {
                if (grid[i][j] == 2 || grid[i][j] == 3) break;
                if (grid[i][j] == 0) grid[i][j] = 1;
                i += dr;
                j += dc;
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto &g : guards) grid[g[0]][g[1]] = 2;
        for (auto &w : walls)  grid[w[0]][w[1]] = 3;

        for (auto &g : guards) markGuards(g[0], g[1], grid);

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) count++;

        return count;
    }
};
