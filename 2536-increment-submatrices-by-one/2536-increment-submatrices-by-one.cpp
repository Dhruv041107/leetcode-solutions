class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> diff(n, vector<int>(n + 1, 0)); 
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            for (int i = r1; i <= r2; i++) {
                diff[i][c1] += 1;
                diff[i][c2 + 1] -= 1;
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int running = 0;
            for (int j = 0; j < n; j++) {
                running += diff[i][j];
                ans[i][j] = running;
            }
        }

        return ans;
    }
};
