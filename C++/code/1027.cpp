class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        vector<vector<int>> dp(n, vector<int>(2000, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 1000;
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};

//   -5 -4 -3 -2 -1 0 1 2 3 4 5 
// 9  1  1  1  1  1 1 1 1 1 1 1
// 4  2  1  1  1  1 1 1 1 1 1 1 
// 7  1  1  1  2  1 1 1 1 2 1 1
// 2  2  1  1  2  1 1 1 1 1 1 1
// 10                     3