class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s;
        for (int day: days) s.insert(day);
        vector<int> dp(366, 0);
        if (s.find(1) != s.end()) dp[1] = min({costs[0], costs[1], costs[2]});
        for (int i = 2; i <= 365; i++) {
            if (s.find(i) == s.end()) dp[i] = dp[i - 1];
            else dp[i] = min({dp[i - 1] + costs[0], (i < 7 ? 0 : dp[i - 7]) + costs[1], (i < 30 ? 0 : dp[i - 30]) + costs[2]});
        }
        return dp[365];
    }
};

// 1 2 3 4 5 6 7 8 9  10 11 12 13 14 15 16 29 30 31
// 2 4 6 7 7 7 7 9 11 13 13 13 13 13 15 15 