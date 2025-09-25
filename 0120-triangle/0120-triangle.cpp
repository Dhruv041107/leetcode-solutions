class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], 
                dp[row + 1][col + 1]);
            }
        }
        return dp[0][0];
    }
};
