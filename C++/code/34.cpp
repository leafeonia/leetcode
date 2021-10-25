class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ansleft = -1, ansright = -1;
        vector<int> ans{-1, -1};
        if (nums.empty()) return ans;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) right = mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        ansleft = left;
        left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] == target) left = mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        ansright = left;
        if (nums[ansleft] == target) {
            ans[0] = ansleft;
            ans[1] = ansright;
        }
        return ans;
    }
};