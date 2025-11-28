class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        dfs(0, -1, g, values, k, ans);
        return ans;
    }
    long long dfs(int u, int parent, const vector<vector<int>>& g, const vector<int>& values, int k, int& ans) {
        long long sum = values[u];
        for (int v : g[u]) {
            if (v == parent) continue;
            sum += dfs(v, u, g, values, k, ans);
        }
        if (sum % k == 0) ++ans;
        return sum;
    }
};
