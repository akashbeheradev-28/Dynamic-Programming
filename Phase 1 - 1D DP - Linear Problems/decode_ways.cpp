// Decode Ways
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION
// ============================================================

class Solution {
public:
    int solve(int i, string s) {
        if(i == s.length())
            return 1;

        if(s[i] == '0')
            return 0;

        int ans = solve(i + 1, s);

        if(i + 1 < s.length()) {
            string str = s.substr(i, 2);

            if(stoi(str) >= 10 && stoi(str) <= 26) {
                ans += solve(i + 2, s);
            }
        }

        return ans;
    }

    int numDecodings(string s) {
        return solve(0, s);
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<int> dp;

    int solve(int i, string s) {
        if(i == s.length())
            return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = solve(i + 1, s);

        if(i + 1 < s.length()) {
            string str = s.substr(i, 2);

            if(stoi(str) >= 10 && stoi(str) <= 26) {
                ans += solve(i + 2, s);
            }
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        dp.assign(s.length(), -1);

        return solve(0, s);
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {

            if(s[i] != '0') {

                dp[i] = dp[i + 1];

                if(i + 1 < n) {
                    string str = s.substr(i, 2);

                    if(stoi(str) >= 10 && stoi(str) <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        return dp[0];
    }
};