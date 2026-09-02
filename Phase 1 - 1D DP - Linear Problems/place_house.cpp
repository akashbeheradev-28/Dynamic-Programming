// 2320. Count Number of Ways to Place Houses
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION--->tle
// ============================================================

class Solution {
public:
    long long mod = 1e9 + 7;

    long long solve(int n) {
        if(n == 1)
            return 2;

        if(n == 2)
            return 3;

        return (solve(n - 1) + solve(n - 2)) % mod;
    }

    int countHousePlacements(int n) {
        long long ans = solve(n);

        return (ans * ans) % mod;
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    long long mod = 1e9 + 7;
    vector<long long> dp;

    long long solve(int n) {
        if(n == 1)
            return 2;

        if(n == 2)
            return 3;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = (solve(n - 1) + solve(n - 2)) % mod;
    }

    int countHousePlacements(int n) {
        dp.assign(n + 1, -1);

        long long ans = solve(n);

        return (ans * ans) % mod;
    }
};


// ============================================================
// 3. TABULATION - SPACE OPTIMIZED
// ============================================================

class Solution {
public:
    long long mod = 1e9 + 7;

    int countHousePlacements(int n) {

        if(n == 1)
            return 4;

        if(n == 2)
            return 9;

        long long prev1 = 2;
        long long prev2 = 3;

        for(int i = 3; i <= n; i++) {

            long long curr = (prev1 + prev2) % mod;

            prev1 = prev2;
            prev2 = curr;
        }

        return (prev2 * prev2) % mod;
    }
};