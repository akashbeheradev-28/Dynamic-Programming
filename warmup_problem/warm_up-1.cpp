LC-70-->https://leetcode.com/problems/climbing-stairs/description/


#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:

/*CRITICAL BUG ITS CLEAR THE TEST CASES BUT ITS A CRITICAL ERROR */
    unordered_map<int, int> mp;
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        // int prev1, prev2; we have declare it but never assigned it
        
        if (mp.find(n - 1) == mp.end())
            mp[n-1] = climbStairs(n - 1);

        if (mp.find(n - 2) == mp.end())
            mp[n-2] = climbStairs(n - 2);

        return mp[n-1] + mp[n-2];
    }
};
int main() {
    Solution s;

    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Number of ways: " << s.climbStairs(n) << endl;

    return 0;
}


/* BUTTOM UP APPROACH WITH O(N),O(1);
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
*/