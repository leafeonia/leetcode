class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int adder = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = max(num1.length(), num2.length());
        for (int i = 0; i < n; i++) {
            int a = i >= num1.length() ? 0 : num1[i] - '0';
            int b = i >= num2.length() ? 0 : num2[i] - '0';
            ans += to_string((a + b + adder) % 10);
            adder = a + b + adder >= 10;
        }
        if (adder) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};