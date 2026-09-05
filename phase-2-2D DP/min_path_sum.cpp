```cpp
// 64. Minimum Path Sum
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION  (TLE)
// ============================================================

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {

        if(i < 0 || j < 0)
            return INT_MAX;

        if(i == 0 && j == 0)
            return grid[i][j];

        int top = solve(i - 1, j, grid);
        int side = solve(i, j - 1, grid);

        return min(top, side) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, grid);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& grid) {

        if(i < 0 || j < 0)
            return INT_MAX;

        if(i == 0 && j == 0)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int top = solve(i - 1, j, grid);
        int side = solve(i, j - 1, grid);

        return dp[i][j] =
            min(top, side) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0)
                    continue;

                int top = INT_MAX;
                int side = INT_MAX;

                if(i > 0)
                    top = dp[i - 1][j];

                if(j > 0)
                    side = dp[i][j - 1];

                dp[i][j] =
                    min(top, side) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
