// Delete and Earn
// Pattern: House Robber
// Recursion -> Memoization -> Tabulation

#include <bits/stdc++.h>
using namespace std;


// ============================================================
// 1. RECURSION
// ============================================================

class Solution {
public:

    int solve(int i, vector<int>& v) {
        if (i >= v.size())
            return 0;

        // Skip current number
        // OR
        // Take current number and skip the next number
        return max(
            solve(i + 1, v),
            solve(i + 2, v) + v[i]
        );
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxelement = *max_element(nums.begin(), nums.end());

        // v[x] = total points obtained by taking number x
        vector<int> v(maxelement + 1, 0);

        for (int x : nums) {
            v[x] += x;
        }

        return solve(0, v);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:

    vector<int> dp;

    int solve(int i, vector<int>& v) {

        if (i >= v.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(
            solve(i + 1, v),
            solve(i + 2, v) + v[i]
        );
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxelement = *max_element(nums.begin(), nums.end());

        vector<int> v(maxelement + 1, 0);

        for (int x : nums) {
            v[x] += x;
        }

        dp.assign(v.size(), -1);

        return solve(0, v);
    }
};


// ============================================================
// 3. TABULATION / SPACE OPTIMIZATION
// ============================================================

class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {

        int maxelement = *max_element(nums.begin(), nums.end());

        vector<int> v(maxelement + 1, 0);

        for (int x : nums) {
            v[x] += x;
        }

        int n = v.size();

        // prev1 = answer for i + 1
        // prev2 = answer for i + 2

        int prev1 = 0;
        int prev2 = 0;

        for (int i = n - 1; i >= 0; i--) {

            int curr = max(
                prev1,
                prev2 + v[i]
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};