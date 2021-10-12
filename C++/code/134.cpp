class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot = 0, cur = 0, n = gas.size(), idx = 0;
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            tot += diff;
            cur += diff;
            if (cur < 0) {
                cur = 0;
                idx = i + 1;
            }
        }
        return tot < 0 ? -1 : idx;
    }
};