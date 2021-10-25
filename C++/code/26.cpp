class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) nums[left++] = nums[i];
        }
        return left;
    }
};