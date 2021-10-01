class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += nums[j] & 1;
                nums[j] >>= 1;
            }
            ans += (n - cnt) * cnt;
        }
        return ans;
    }
};

// 5 1 1 1 0 0   2 + 2 + 2 + 3 + 3