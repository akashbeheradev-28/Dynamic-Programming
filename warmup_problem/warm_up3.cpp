//279. Perfect Squares-->https://leetcode.com/problems/perfect-squares/description/

#include<iostream>
#include<map>
#include<climits>
using namespace std;
class Solution {
public:
    unordered_map<int,int>mp;
    int numSquares(int n) {
        if(n<=3) return n;

        if(mp.find(n)!=mp.end()) return mp[n];

        int min_square=INT_MAX;
        for(int i=1;i*i<=n;i++){
            min_square=min(min_square,1+numSquares(n-i*i));
        }
        mp[n]=min_square;
        return mp[n];
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.numSquares(n)<<endl;
    return 0;
}