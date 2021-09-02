
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int ans = 0;
        int sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -1 : 1;
        if (divisor > 0) divisor = -divisor;
        if (dividend > 0) dividend = -dividend;
        while (dividend <= divisor) {
            int cnt = -1;
            int subtractor = divisor;
            while (subtractor > INT_MIN / 2 && subtractor + subtractor >= dividend) {
                cnt += cnt;
                subtractor += subtractor;
            }
            ans += cnt;
            dividend -= subtractor;
        }
        return -sign * ans;
    }
};
