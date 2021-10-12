class Solution {
public:
    int countOrders(int n) {
        long ans = 1, mod = 1e9 + 7;
        // (2 * x - 1) * x
        for (int i = 1; i <= n; i++) {
            ans = ans * (2 * i - 1) * i % mod;
        }
        return ans;
    }
};