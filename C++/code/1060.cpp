class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] - nums[0] - mid >= k) right = mid - 1;
            else left = mid;
        }
        return nums[left] + k - (nums[left] - left - nums[0]);
    }
};