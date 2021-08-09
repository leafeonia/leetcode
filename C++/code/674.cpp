class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int curLength = 1;
        int curVal = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > curVal) {
                curLength++;
            } else {
                ans = max(ans, curLength);
                curLength = 1;
            }
            curVal = nums[i];
        }
        ans = max(ans, curLength);
        return ans;
    }
};