class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maximum = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            sum += weights[i];
            maximum = max(maximum, weights[i]);
        }
        int left = maximum, right = sum;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cur = 0, cnt = 1;
            for (int i = 0; i < n; i++) {
                cur += weights[i];
                if (cur > mid) {
                    cnt++;
                    cur = weights[i];
                }
            }
            if (cnt <= days) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};