```cpp
// Dungeon Game
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION---Got TLE :)
// ============================================================

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& v) {

        if (i == v.size() - 1 && j == v[0].size() - 1)
            return max(1, 1 - v[i][j]);

        if (i >= v.size() || j >= v[0].size())
            return INT_MAX;

        int next = min(
            solve(i + 1, j, v),
            solve(i, j + 1, v)
        );

        return max(1, next - v[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& v) {
        return solve(0, 0, v);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& v) {

        if (i == v.size() - 1 && j == v[0].size() - 1)
            return max(1, 1 - v[i][j]);

        if (i >= v.size() || j >= v[0].size())
            return INT_MAX;

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int next = min(
            solve(i + 1, j, v),
            solve(i, j + 1, v)
        );

        return dp[i][j] = max(1, next - v[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(m, vector<int>(n, INT_MAX));

        return solve(0, 0, v);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    vector<vector<int>> dp;

    int calculateMinimumHP(vector<vector<int>>& v) {

        int m = v.size();
        int n = v[0].size();

        dp.assign(m + 1, vector<int>(n + 1, INT_MAX));

        dp[m - 1][n - 1] =
            max(1, 1 - v[m - 1][n - 1]);

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                int next = min(
                    dp[i + 1][j],
                    dp[i][j + 1]
                );

                dp[i][j] = max(1, next - v[i][j]);
            }
        }

        return dp[0][0];
    }
};
```

**Complexity:**

* Recursion → exponential → **TLE**
* Memoization → `O(m × n)` time, `O(m × n)` space
* Tabulation → `O(m × n)` time, `O(m × n)` space

And your key recurrence for this problem is:

```text
dp[i][j] = max(1, min(below, right) - v[i][j])
```


