class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, int compID, vector<int>& compOf, vector< set<int> >& comps,
    vector<bool>& visited) {
        visited[u] = true;
        compOf[u] = compID;
        comps[compID].insert(u);
        for(int v : adj[u]) {
            if(!visited[v]) {
                dfs(v, adj, compID, compOf, comps, visited);
            }
        }
    }
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c+1);
        for(auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(c+1,false);
        vector<int> compOf(c+1,-1);
        vector< set<int> > comps(c+1);
        int compCount=0;
        for(int u=1; u<=c; u++) {
            if(!visited[u]) {
                dfs(u, adj, compCount, compOf, comps, visited);
                compCount++;
            }
        }
        
        vector<int> result;
        for(auto &q : queries) {
            int type = q[0], node = q[1];
            int cid = compOf[node];
            if(type == 1) {
                if(comps[cid].empty()) {
                    result.push_back(-1);
                } else if(comps[cid].count(node)) {
                    result.push_back(node);
                } else {
                    result.push_back(*comps[cid].begin());
                }
            } else {
                comps[cid].erase(node);
            }
        }
        return result;
    }
};
