class Solution {
public:
    //       1  2  3
    // x     4  5  6
    //       6  12 18
    //    5  10 15
    // 4  8  12
    //          28  8
    //       30 8   8
    // 4  16 0  8   8
    // 5  6  0  8   8
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        vector<int> v(n1 + n2, 0);
        for (int i = n2 - 1; i >= 0; i--) {
            int base = n2 - i - 1;
            for (int j = n1 - 1; j >= 0; j--) {
                v[base + n1 - j - 1] += (num1[j] - '0') * (num2[i] - '0');
            }
        }
        int idx = 0;
        string ans;
        for (int i = 0; i < n1 + n2; i++) {
            if (v[i] >= 10) {
                v[i + 1] += v[i] / 10;
            }
            ans += v[i] % 10 + '0';
        }
        while (ans.length() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};