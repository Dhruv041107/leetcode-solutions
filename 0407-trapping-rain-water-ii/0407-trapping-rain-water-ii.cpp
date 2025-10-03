class Solution {
public:
    typedef pair<int,pair<int,int>> PP;
    vector<vector<int>>direction={{0,-1},{1,0},{-1,0},{0,1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();

        priority_queue<PP,vector<PP>,greater<>>pq;

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int row=0;row<m;row++){
            for(int col:{0,n-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        for(int col=0;col<n;col++){
            for(int row:{0,m-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }
        int water=0;

        while(!pq.empty()){
            PP p=pq.top();
            pq.pop();
            int height=p.first;
            int i=p.second.first;
            int j=p.second.second;        

            for(auto &dir:direction){
                int newI=i+dir[0];
                int newJ=j+dir[1];

                if(newI<m && newI>=0 && newJ<n && newJ>=0 && !visited[newI][newJ]){
                    water+=max(height-heightMap[newI][newJ],0);

                    pq.push({max(height,heightMap[newI][newJ]),{newI,newJ}});
                    visited[newI][newJ]=true;
                }
            }
        }
        return water;
    }
};