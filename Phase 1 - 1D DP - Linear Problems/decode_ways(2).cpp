// Decode Ways II
// Recursion -> Memoization -> Tabulation


// ============================================================
// 1. RECURSION
// ============================================================

class Solution {
public:
    long long mod = 1e9 + 7;

    long long solve(int i, string s) {
        if(i == s.length())
            return 1;

        if(s[i] == '0')
            return 0;

        long long ans;

        if(s[i] == '*') {
            ans = 9 * solve(i + 1, s) % mod;
        }
        else {
            ans = solve(i + 1, s) % mod;
        }

        if(i + 1 < s.length()) {

            string k = s.substr(i, 2);

            char first = k[0];
            char second = k[1];

            if(first == '*' && second == '*') {
                ans = (ans + 15 * solve(i + 2, s)) % mod;
            }

            else if(first == '*') {
                if(second >= '0' && second <= '6') {
                    ans = (ans + 2 * solve(i + 2, s)) % mod;
                }
                else {
                    ans = (ans + solve(i + 2, s)) % mod;
                }
            }

            else if(second == '*') {
                if(first == '1') {
                    ans = (ans + 9 * solve(i + 2, s)) % mod;
                }
                else if(first == '2') {
                    ans = (ans + 6 * solve(i + 2, s)) % mod;
                }
            }

            else {
                int num = (first - '0') * 10 + (second - '0');

                if(num >= 10 && num <= 26) {
                    ans = (ans + solve(i + 2, s)) % mod;
                }
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
    long long mod = 1e9 + 7;
    vector<long long> dp;

    long long solve(int i, string s) {
        if(i == s.length())
            return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        long long ans;

        if(s[i] == '*') {
            ans = 9 * solve(i + 1, s) % mod;
        }
        else {
            ans = solve(i + 1, s) % mod;
        }

        if(i + 1 < s.length()) {

            string k = s.substr(i, 2);

            char first = k[0];
            char second = k[1];

            if(first == '*' && second == '*') {
                ans = (ans + 15 * solve(i + 2, s)) % mod;
            }

            else if(first == '*') {
                if(second >= '0' && second <= '6') {
                    ans = (ans + 2 * solve(i + 2, s)) % mod;
                }
                else {
                    ans = (ans + solve(i + 2, s)) % mod;
                }
            }

            else if(second == '*') {
                if(first == '1') {
                    ans = (ans + 9 * solve(i + 2, s)) % mod;
                }
                else if(first == '2') {
                    ans = (ans + 6 * solve(i + 2, s)) % mod;
                }
            }

            else {
                int num = (first - '0') * 10 + (second - '0');

                if(num >= 10 && num <= 26) {
                    ans = (ans + solve(i + 2, s)) % mod;
                }
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
    long long mod = 1e9 + 7;

    int numDecodings(string s) {
        int n = s.size();

        vector<long long> dp(n + 1, 0);

        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {

            if(s[i] != '0') {

                long long ans;

                // Single character
                if(s[i] == '*') {
                    ans = 9 * dp[i + 1] % mod;
                }
                else {
                    ans = dp[i + 1];
                }

                // Two characters
                if(i + 1 < n) {

                    char first = s[i];
                    char second = s[i + 1];

                    if(first == '*' && second == '*') {
                        ans = (ans + 15 * dp[i + 2]) % mod;
                    }

                    else if(first == '*') {
                        if(second >= '0' && second <= '6') {
                            ans = (ans + 2 * dp[i + 2]) % mod;
                        }
                        else {
                            ans = (ans + dp[i + 2]) % mod;
                        }
                    }

                    else if(second == '*') {
                        if(first == '1') {
                            ans = (ans + 9 * dp[i + 2]) % mod;
                        }
                        else if(first == '2') {
                            ans = (ans + 6 * dp[i + 2]) % mod;
                        }
                    }

                    else {
                        int num = (first - '0') * 10 + (second - '0');

                        if(num >= 10 && num <= 26) {
                            ans = (ans + dp[i + 2]) % mod;
                        }
                    }
                }

                dp[i] = ans;
            }
        }

        return dp[0];
    }
};