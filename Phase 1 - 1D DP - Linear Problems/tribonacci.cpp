//1137. N-th Tribonacci Number-- take care about base cases 

//==================Recursion=======================got tle :)
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==2 || n==1) return 1;

        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};


//=================Memoization================================
class Solution {
public:
    vector<int>dp;
    int solve(int n){
        if(n==0) return 0;
        if(n==2 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=solve(n-1)+solve(n-2)+solve(n-3);
    }
    int tribonacci(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};


//================tabulation====================================
class Solution {
public:
    vector<int>dp;

    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        dp.assign(n+1,0);
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }

        
        return dp[n];
    }
};