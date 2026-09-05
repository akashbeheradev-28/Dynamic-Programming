// 63. Unique Paths II
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION  (TLE)
// ============================================================

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& v) {

        if(v[i][j] == 1)
            return 0;

        if(i == 0 && j == 0)
            return 1;

        int ans = 0;

        if(i > 0)
            ans += solve(i - 1, j, v);

        if(j > 0)
            ans += solve(i, j - 1, v);

        return ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        return solve(m - 1, n - 1, v);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& v) {

        if(v[i][j] == 1)
            return 0;

        if(i == 0 && j == 0)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if(i > 0)
            ans += solve(i - 1, j, v);

        if(j > 0)
            ans += solve(i, j - 1, v);

        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, v);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if(v[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(v[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if(i > 0)
                    dp[i][j] += dp[i - 1][j];

                if(j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};