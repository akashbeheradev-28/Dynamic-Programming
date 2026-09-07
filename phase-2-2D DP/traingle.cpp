/* 1. Recursion got      TLE

```cpp*/
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& v) {
        if (i == v.size() - 1)
            return v[i][j];

        return v[i][j] + min(
            solve(i + 1, j, v),
            solve(i + 1, j + 1, v)
        );
    }

    int minimumTotal(vector<vector<int>>& v) {
        return solve(0, 0, v);
    }
};
```

/*---

### 2. Memoization

```cpp*/
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& v) {
        if (i == v.size() - 1)
            return v[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        return dp[i][j] =
            v[i][j] + min(
                solve(i + 1, j, v),
                solve(i + 1, j + 1, v)
            );
    }

    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();

        dp.assign(n, vector<int>(n, INT_MAX));

        return solve(0, 0, v);
    }
};
```

---

/* 3. Tabulation

```cpp*/
class Solution {
public:
    vector<vector<int>> dp;

    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();

        dp.assign(n, vector<int>(n, INT_MAX));

        // Base case: last row
        int m = v[n - 1].size();

        for (int j = m - 1; j >= 0; j--) {
            dp[n - 1][j] = v[n - 1][j];
        }

        // Build from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            int k = v[i].size();

            for (int j = k - 1; j >= 0; j--) {
                dp[i][j] =
                    min(dp[i + 1][j], dp[i + 1][j + 1]) + v[i][j];
            }
        }

        return dp[0][0];
    }
};
```

// **Pattern:** `solve(i, j)` → two choices → `(i+1, j)` or `(i+1, j+1)` → take the minimum.

// **Complexity:**

// * Recursion: `O(2^n)`
// * Memoization: `O(n²)` time, `O(n²)` space
// * Tabulation: `O(n²)` time, `O(n²)` space
