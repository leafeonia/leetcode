class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int right = -1;
        int leftmax = nums[0];
        for (int i = 1; i < n; i++) {
            leftmax = max(leftmax, nums[i]);
            if (nums[i] < leftmax) right = i;
        }
        int left = 0;
        int rightmin = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmin = min(rightmin, nums[i]);
            if (nums[i] > rightmin) left = i;
        }
        return right - left + 1;
    }
};
