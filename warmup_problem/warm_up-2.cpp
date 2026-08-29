/*1137. N-th Tribonacci Number -->https://leetcode.com/problems/n-th-tribonacci-number/description/*/

// ----------BUTTOM UP APPROACH---------------
#include<iostream>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;

        int prev1=0;
        int prev2=0;
        int prev3=1;


        for(int i=2;i<=n;i++){
            int curr=prev1+prev2+prev3;
            prev1=prev2;
            prev2=prev3;
            prev3=curr;
        }

        return prev3;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.tribonacci(n);
    return 0;
}


/*---------TOP DOWN APPROACH----------------
class Solution {
public:
    unordered_map<int,int>mp;
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;

        int prev1=(n-1);
        int prev2=(n-2);
        int prev3=(n-3);


        if(mp.find(prev1)==mp.end()){
            mp[prev1]=tribonacci(prev1);
        }
        if(mp.find(prev2)==mp.end()){
            mp[prev2]=tribonacci(prev2);
        }
        if(mp.find(prev3)==mp.end()){
            mp[prev3]=tribonacci(prev3);
        }



        return mp[prev1]+mp[prev2]+mp[prev3];
    }
};

*/