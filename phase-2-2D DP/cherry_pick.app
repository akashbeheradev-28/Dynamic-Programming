```cpp
// Cherry Pickup I
// Recursion -> Memoization

// ============================================================
// 1. RECURSION --- Got TLE :)
// ============================================================

class Solution {
public:
    int solve(int i, int j, int k, int l, vector<vector<int>>& v) {

        if (i >= v.size() || j >= v[0].size() ||
            k >= v.size() || l >= v[0].size())
            return INT_MIN;

        if (v[i][j] == -1 || v[k][l] == -1)
            return INT_MIN;

        if (i == v.size() - 1 && j == v[0].size() - 1)
            return v[i][j];

        int cherry;

        if (i == k && j == l)
            cherry = v[i][j];
        else
            cherry = v[i][j] + v[k][l];

        int next = max({
            solve(i + 1, j, k + 1, l, v),
            solve(i + 1, j, k, l + 1, v),
            solve(i, j + 1, k + 1, l, v),
            solve(i, j + 1, k, l + 1, v)
        });

        if (next == INT_MIN)
            return INT_MIN;

        return cherry + next;
    }

    int cherryPickup(vector<vector<int>>& v) {

        int ans = solve(0, 0, 0, 0, v);

        if (ans < 0)
            return 0;

        return ans;
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;

    int solve(int i, int j, int k, int l, vector<vector<int>>& v) {

        if (i >= v.size() || j >= v[0].size() ||
            k >= v.size() || l >= v[0].size())
            return INT_MIN;

        if (v[i][j] == -1 || v[k][l] == -1)
            return INT_MIN;

        if (i == v.size() - 1 && j == v[0].size() - 1)
            return v[i][j];

        if (dp[i][j][k][l] != INT_MIN)
            return dp[i][j][k][l];

        int cherry;

        if (i == k && j == l)
            cherry = v[i][j];
        else
            cherry = v[i][j] + v[k][l];

        int next = max({
            solve(i + 1, j, k + 1, l, v),
            solve(i + 1, j, k, l + 1, v),
            solve(i, j + 1, k + 1, l, v),
            solve(i, j + 1, k, l + 1, v)
        });

        if (next == INT_MIN)
            return dp[i][j][k][l] = INT_MIN;

        return dp[i][j][k][l] = cherry + next;
    }

    int cherryPickup(vector<vector<int>>& v) {

        int n = v.size();

        dp.assign(
            n,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    n,
                    vector<int>(n, INT_MIN)
                )
            )
        );

        int ans = solve(0, 0, 0, 0, v);

        if (ans < 0)
            return 0;

        return ans;
    }
};
```

**Note:** For Cherry Pickup I, you stopped at memoization because the 4D → 3D state optimization was not implemented. That's perfectly fine for your GitHub progression.
