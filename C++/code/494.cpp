class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if ((sum + target) % 2 == 1) return 0;
        sum = (sum + target) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
}; 
// x: sum of all positive elements
// x - (sum - x) = target
// x = (target + sum) / 2
