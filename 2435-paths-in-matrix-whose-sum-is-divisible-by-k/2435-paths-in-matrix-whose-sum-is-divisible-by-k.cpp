class Solution {
public:
    int n, m, K;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    using ll = long long;

    int solve(int i, int j, int rem, vector<vector<int>>& grid) {
        if (i == n-1 && j == m-1) {
            int newRem = (rem + grid[i][j]) % K;
            return newRem == 0;
        }

        if (dp[i][j][rem] != -1) return dp[i][j][rem];

        ll ways = 0;
        int newRem = (rem + grid[i][j]) % K;

        if (i + 1 < n) 
            ways += solve(i+1, j, newRem, grid);

        if (j + 1 < m) 
            ways += solve(i, j+1, newRem, grid);

        return dp[i][j][rem] = ways % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;

        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return solve(0, 0, 0, grid);
    }
};
