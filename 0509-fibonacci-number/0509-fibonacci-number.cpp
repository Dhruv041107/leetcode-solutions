class Solution {
public:
    int solveusingRecursion(int n) {
        if (n == 1) return 1;
        if (n == 0) return 0;
        return solveusingRecursion(n - 1) + solveusingRecursion(n - 2);
    }

    int solveusingMem(int n, vector<int> &dp) {
        if (n == 1) return 1;
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        dp[n] = solveusingMem(n - 1, dp) + solveusingMem(n - 2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solveusingMem(n, dp);
    }
};  // <-- this closing brace and semicolon were missing
