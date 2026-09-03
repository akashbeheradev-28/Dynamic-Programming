// 2140. Solving Questions With Brainpower
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION  (TLE)
// ============================================================

class Solution {
public:
    long long solve(int i, vector<vector<int>>& v) {
        if(i >= v.size())
            return 0;

        return max(
            solve(i + 1, v),
            v[i][0] + solve(i + v[i][1] + 1, v)
        );
    }

    long long mostPoints(vector<vector<int>>& questions) {
        return solve(0, questions);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<long long> dp;

    long long solve(int i, vector<vector<int>>& v) {
        if(i >= v.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        return dp[i] = max(
            solve(i + 1, v),
            v[i][0] + solve(i + v[i][1] + 1, v)
        );
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        dp.assign(n, -1);

        return solve(0, questions);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    vector<long long> dp;

    long long mostPoints(vector<vector<int>>& v) {
        int n = v.size();

        dp.assign(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            if(i + v[i][1] + 1 < dp.size()) {
                dp[i] = max(
                    dp[i + 1],
                    v[i][0] + dp[i + v[i][1] + 1]
                );
            }
            else {
                dp[i] = max(
                    dp[i + 1],
                    (long long)v[i][0]
                );
            }
        }

        return dp[0];
    }
};