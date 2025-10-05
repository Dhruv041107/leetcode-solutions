class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(vector<vector<int>>& heights,int i,int j,int prevElement,vector<vector<bool>>&visited){
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()
            || heights[i][j] < prevElement || visited[i][j]) return;


        visited[i][j]=true;

        for(auto &d:dir){
            int newi=i+d[0];
            int newj=j+d[1];
            DFS(heights,newi,newj,heights[i][j],visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>result;

        vector<vector<bool>>pacificOcean(m,vector<bool>(n,false));
        vector<vector<bool>>atlanticOcean(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            DFS(heights,0,j,INT_MIN,pacificOcean);
            DFS(heights,m-1,j,INT_MIN,atlanticOcean);
        }

        for(int i=0;i<m;i++){
            DFS(heights,i,0,INT_MIN,pacificOcean);
            DFS(heights,i,n-1,INT_MIN,atlanticOcean);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificOcean[i][j] && atlanticOcean[i][j])   result.push_back({i,j});
            }
        }
        return result;
    }
};