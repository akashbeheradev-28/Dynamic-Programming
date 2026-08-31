// Jump Game II
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION-->i got TLE
// ============================================================

class Solution {
public:
    int solve(int i, vector<int>& v) {
        if(i == v.size() - 1)
            return 0;

        if(v[i] == 0)
            return INT_MAX;

        int ans = INT_MAX;

        for(int j = 1; j <= v[i] && i + j < v.size(); j++) {
            int next = solve(i + j, v);

            if(next != INT_MAX)
                ans = min(ans, next + 1);//not min(ans,next)+1
        }

        return ans;
    }

    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& v) {
        if(i == v.size() - 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for(int j = 1; j <= v[i] && i + j < v.size(); j++) {
            int next = solve(i + j, v);

            if(next != INT_MAX)
                ans = min(ans, next + 1);
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);

        return solve(0, nums);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(n, INT_MAX);

        v[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--) {

            int num = nums[i];

            for(int j = i + 1; j < n && num > 0; j++, num--) {

                int next = v[j];

                if(v[j] != INT_MAX)
                    v[i] = min(v[i], next + 1);
            }
        }

        return v[0];
    }
};