class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ans = INT_MIN;
        int sum = 0;
        for (int num: nums) {
            sum += num;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};
