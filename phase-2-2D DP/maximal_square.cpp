
// Maximal Square lc-221
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION---Got TLE :)
// ============================================================

class Solution {
public:
    int solve(int i, int j, vector<vector<char>>& v) {
        if (i >= v.size() || j >= v[0].size())
            return 0;

        if (v[i][j] == '0')
            return 0;

        return 1 + min({
            solve(i + 1, j, v),
            solve(i, j + 1, v),
            solve(i + 1, j + 1, v)
        });
    }

    int maximalSquare(vector<vector<char>>& v) {

        int ans = 0;

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {

                ans = max(solve(i, j, v), ans);
            }
        }

        return ans * ans;
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<char>>& v) {
        if (i >= v.size() || j >= v[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (v[i][j] == '0')
            return dp[i][j] = 0;

        return dp[i][j] = 1 + min({
            solve(i + 1, j, v),
            solve(i, j + 1, v),
            solve(i + 1, j + 1, v)
        });
    }

    int maximalSquare(vector<vector<char>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                ans = max(solve(i, j, v), ans);
            }
        }

        return ans * ans;
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int maximalSquare(vector<vector<char>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(m + 1, vector<int>(n + 1, 0));

        int ans = 0;

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (v[i][j] == '0')
                    continue;

                dp[i][j] = 1 + min({
                    dp[i + 1][j],
                    dp[i][j + 1],
                    dp[i + 1][j + 1]
                });

                ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};
```

**Complexity:**

* Recursion → `O(m × n × exponential)` — TLE
* Memoization → `O(m × n)` time, `O(m × n)` space
* Tabulation → `O(m × n)` time, `O(m × n)` space

Nice one. This was your first **2D DP where each state depends on three neighboring states** — and you derived the recurrence yourself. 🔥
