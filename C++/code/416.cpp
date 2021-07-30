class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int num: nums) sum += num;
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j >= nums[i]) dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};