// 62. Unique Paths
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION  (TLE)
// ============================================================

class Solution {
public:
    int solve(int i, int j) {

        if(i == 0 || j == 0)
            return 1;

        return solve(i - 1, j) + solve(i, j - 1);
    }

    int uniquePaths(int m, int n) {
        return solve(m - 1, n - 1);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j) {

        if(i == 0 || j == 0)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(i - 1, j) + solve(i, j - 1);
    }

    int uniquePaths(int m, int n) {

        dp.assign(m, vector<int>(n, -1));

        return solve(m - 1, n - 1);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            dp[i][0] = 1;

        for(int j = 0; j < n; j++)
            dp[0][j] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                dp[i][j] =dp[i - 1][j] +dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};