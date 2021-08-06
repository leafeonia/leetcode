class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(nums[0], max(nums[1], nums[2]));
        vector<int> dpWithFirst(n, 0);
        vector<int> dpWithoutFirst(n, 0);
        dpWithFirst[0] = nums[0];
        dpWithFirst[1] = max(nums[0], nums[1]);
        dpWithoutFirst[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dpWithFirst[i] = max(dpWithFirst[i - 2] + nums[i], dpWithFirst[i - 1]);
            dpWithoutFirst[i] = max(dpWithoutFirst[i - 2] + nums[i], dpWithoutFirst[i - 1]);
        }
        dpWithFirst[n - 1] = dpWithFirst[n - 2];
        dpWithoutFirst[n - 1] = max(dpWithoutFirst[n - 3] + nums[n - 1], dpWithoutFirst[n - 2]);
        return max(dpWithFirst[n - 1], dpWithoutFirst[n - 1]);
    }
};