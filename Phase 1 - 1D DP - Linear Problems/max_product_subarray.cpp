// Maximum Product Subarray
// Recursion -> Memoization -> Tabulation
//============================================================
// 0.Brute force
//=============================================================
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),max_product=INT_MIN;
        for(int i=n-1;i>=0;i--){
            
            // int num=product;
            for(int j=0;j<=i;j++){
                int product=1;
                for(int k=j;k<=i;k++){
                    product*=nums[k];
                }
                max_product=max(max_product,product);
            }
              
        }
        return max_product;
    }
};

// ============================================================
// 1. RECURSION
// ============================================================

class Solution {
public:
    int ans = INT_MIN;

    pair<int, int> solve(int i, vector<int>& nums) {
        if (i == 0)
            return {nums[0], nums[0]};

        auto prev = solve(i - 1, nums);

        int currMax = max({
            nums[i],
            nums[i] * prev.first,
            nums[i] * prev.second
        });

        int currMin = min({
            nums[i],
            nums[i] * prev.first,
            nums[i] * prev.second
        });

        ans = max(ans, currMax);

        return {currMax, currMin};
    }

    int maxProduct(vector<int>& nums) {
        ans = nums[0];

        solve(nums.size() - 1, nums);

        return ans;
    }
};


// ============================================================
// 2. MEMOIZATION
// ============================================================

class Solution {
public:
    vector<pair<int, int>> dp;
    int ans = INT_MIN;

    pair<int, int> solve(int i, vector<int>& nums) {
        if (i == 0)
            return {nums[0], nums[0]};

        if (dp[i].first != INT_MIN)
            return dp[i];

        auto prev = solve(i - 1, nums);

        int currMax = max({
            nums[i],
            nums[i] * prev.first,
            nums[i] * prev.second
        });

        int currMin = min({
            nums[i],
            nums[i] * prev.first,
            nums[i] * prev.second
        });

        ans = max(ans, currMax);

        return dp[i] = {currMax, currMin};
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n, {INT_MIN, INT_MIN});

        ans = nums[0];

        solve(n - 1, nums);

        return ans;
    }
};


// ============================================================
// 3. TABULATION
// ============================================================

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> minimum(n);
        vector<int> maximum(n);

        minimum[0] = nums[0];
        maximum[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            minimum[i] = min(
                nums[i],
                min(
                    nums[i] * minimum[i - 1],
                    nums[i] * maximum[i - 1]
                )
            );

            maximum[i] = max(
                nums[i],
                max(
                    nums[i] * minimum[i - 1],
                    nums[i] * maximum[i - 1]
                )
            );

            ans = max(ans, max(minimum[i], maximum[i]));
        }

        return ans;
    }
};