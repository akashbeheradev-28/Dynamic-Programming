// Jump Game
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION---Got TLE :)
// ============================================================

class Solution {
public:
    bool solve(int i, vector<int>& v) {
        if (i == v.size() - 1)
            return true;

        bool ans = false;

        for (int j = 1; j <= v[i] && i + j < v.size(); j++) {
            ans = ans || solve(i + j, v);
        }

        return ans;
    }

    bool canJump(vector<int>& nums) {
        return solve(0, nums);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<int> dp;

    bool solve(int i, vector<int>& v) {
        if (i == v.size() - 1)
            return true;

        if (dp[i] != -1)
            return dp[i];

        bool ans = false;

        for (int j = 1; j <= v[i] && i + j < v.size(); j++) {
            ans = ans || solve(i + j, v);
        }

        return dp[i] = ans;
    }

    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(), -1);

        return solve(0, nums);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n, false);

        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {

            int num = nums[i];

            for (int j = i + 1; j < n && num > 0; j++, num--) {

                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};