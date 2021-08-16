class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;
        int hold = -prices[0];
        int notHold = 0;
        for (int i = 1; i < n; i++) {
            int temp = hold;
            hold = max(hold, notHold - prices[i]);
            notHold = max(notHold, temp + prices[i] - fee);
        }
        return notHold;
    }
};

//  hold  not hold
//1  -1   0
//3  -1   0
//2  -1   0
//8  -1   5
//4   1   5
//9   1   8