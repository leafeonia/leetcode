class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, ans = 0, cnt = 0;
        while (right < n) {
            if (nums[right] == 0) cnt++;
            while (cnt > k) {
                if (nums[left++] == 0) cnt--;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};