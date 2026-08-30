//198. House Robber-->https://leetcode.com/problems/house-robber/description/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(nums.size()==0) return 0;
        if(n<=2) return *max_element(nums.begin(),nums.end());//imp that this fun return a *pointer

        int prev1=nums[0];//dp[n-2]
        int prev2=max(prev1,nums[1]);//max element between first two due to thsi case--> [2,1,1,2]
        for(int i=2;i<n;i++){
            int curr=max(prev2,nums[i]+prev1);
            prev1=prev2;
            prev2=curr;
        }


        return prev2;//return last element
    }
};
int main(){
Solution s;
int n;
cin>>n;
cout<<s.rob(n)<<endl;
return 0;
}