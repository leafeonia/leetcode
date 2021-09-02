class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt1 = 0;
        int maxNum = 0;
        for (int num: nums) {
            if (num == 1) cnt1++; 
            maxNum = max(maxNum, num);
            mp[num]++;
        }
        vector<int> dp(maxNum + 1, 0);
        dp[1] = cnt1;
        for (int i = 2; i <= maxNum; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * mp[i]);
        }
        return dp[maxNum];
    }
};