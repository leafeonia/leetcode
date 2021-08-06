class Solution {
public:
    int n;
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(nums[0], max(nums[1], nums[2]));
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
    
    int solve(vector<int> nums, int start, int end) {
        vector<int> dp(n, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};