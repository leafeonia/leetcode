class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1, cur = x;
        while (N) {
            if (N & 1) {
                ans *= cur;
            }
            cur *= cur;
            N >>= 1;
        }
        return ans;
    }
};

// a ^ 13(1101)
// a