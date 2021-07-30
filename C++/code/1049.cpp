class Solution {
public:
    
    //find the max value <= sum / 2
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int stone: stones) sum += stone;
        int bagWeight = sum / 2;
        vector<int> dp(bagWeight + 1, 0); //dp[i] denotes the max value with weight i
        for (int stone: stones) {
            for (int j = bagWeight; j >= stone; j--) {
                dp[j] = max(dp[j], dp[j - stone] + stone); // first stone is weight, second stone is value
            }
        }
        return sum - 2 * dp[bagWeight];
    }
};