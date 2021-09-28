class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    ans += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};