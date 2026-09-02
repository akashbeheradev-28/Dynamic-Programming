//509. Fibonacci Number

//========================recursion============================
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1)  return 1;

        return fib(n-1)+fib(n-2);
    }
};


//========================memoization==========================
class Solution {
public:
    vector<int>dp;
    int solve(int n){
        if(n==0) return 0;
        if(n==1)  return 1;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=solve(n-1)+solve(n-2);
    }
    int fib(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};

//==========================tabulation===========================
class Solution {
public:
    vector<int>dp;

    int fib(int n) {
        if(n==0) return 0;//if i miss it we get buffer-overflow error for test case n=0;
        dp.assign(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};