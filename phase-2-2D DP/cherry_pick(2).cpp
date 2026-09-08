```cpp
// Cherry Pickup II
// Recursion -> Memoization -> Tabulation

// ============================================================
// 1. RECURSION --- Got TLE :)
// ============================================================

class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& v) {

        if (j < 0 || j >= v[0].size() ||
            k < 0 || k >= v[0].size())
            return INT_MIN;

        if (i == v.size() - 1) {

            if (j == k)
                return v[i][j];

            return v[i][j] + v[i][k];
        }

        int cherry;

        if (j == k)
            cherry = v[i][j];
        else
            cherry = v[i][j] + v[i][k];

        int next = max({
            solve(i + 1, j - 1, k - 1, v),
            solve(i + 1, j - 1, k, v),
            solve(i + 1, j - 1, k + 1, v),

            solve(i + 1, j, k - 1, v),
            solve(i + 1, j, k, v),
            solve(i + 1, j, k + 1, v),

            solve(i + 1, j + 1, k - 1, v),
            solve(i + 1, j + 1, k, v),
            solve(i + 1, j + 1, k + 1, v)
        });

        if (next == INT_MIN)
            return INT_MIN;

        return cherry + next;
    }

    int cherryPickup(vector<vector<int>>& v) {

        int n = v[0].size();

        return solve(0, 0, n - 1, v);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k, vector<vector<int>>& v) {

        if (j < 0 || j >= v[0].size() ||
            k < 0 || k >= v[0].size())
            return INT_MIN;

        if (i == v.size() - 1) {

            if (j == k)
                return v[i][j];

            return v[i][j] + v[i][k];
        }

        if (dp[i][j][k] != INT_MIN)
            return dp[i][j][k];

        int cherry;

        if (j == k)
            cherry = v[i][j];
        else
            cherry = v[i][j] + v[i][k];

        int next = max({
            solve(i + 1, j - 1, k - 1, v),
            solve(i + 1, j - 1, k, v),
            solve(i + 1, j - 1, k + 1, v),

            solve(i + 1, j, k - 1, v),
            solve(i + 1, j, k, v),
            solve(i + 1, j, k + 1, v),

            solve(i + 1, j + 1, k - 1, v),
            solve(i + 1, j + 1, k, v),
            solve(i + 1, j + 1, k + 1, v)
        });

        if (next == INT_MIN)
            return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = cherry + next;
    }

    int cherryPickup(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(n, INT_MIN)
            )
        );

        return solve(0, 0, n - 1, v);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    vector<vector<vector<int>>> dp;

    int cherryPickup(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(
            m,
            vector<vector<int>>(
                n + 2,
                vector<int>(n + 2, INT_MIN)
            )
        );

        // Last row
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {

                if (j == k)
                    dp[m - 1][j + 1][k + 1] = v[m - 1][j];
                else
                    dp[m - 1][j + 1][k + 1] =
                        v[m - 1][j] + v[m - 1][k];
            }
        }

        // Fill from bottom to top
        for (int i = m - 2; i >= 0; i--) {

            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {

                    int cherry;

                    if (j == k)
                        cherry = v[i][j - 1];
                    else
                        cherry = v[i][j - 1] + v[i][k - 1];

                    int next = max({
                        dp[i + 1][j - 1][k - 1],
                        dp[i + 1][j - 1][k],
                        dp[i + 1][j - 1][k + 1],

                        dp[i + 1][j][k - 1],
                        dp[i + 1][j][k],
                        dp[i + 1][j][k + 1],

                        dp[i + 1][j + 1][k - 1],
                        dp[i + 1][j + 1][k],
                        dp[i + 1][j + 1][k + 1]
                    });

                    if (next != INT_MIN)
                        dp[i][j][k] = cherry + next;
                }
            }
        }

        return dp[0][1][n];
    }
};

