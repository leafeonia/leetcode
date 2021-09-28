class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int idx = 0;
        int n = s.length();
        int sign = 1;
        
        while (idx < n && s[idx] == ' ') idx++;
        if (s[idx] == '+' || s[idx] == '-') {
            if (s[idx] == '-') sign = -1;
            idx++;
        }
        while (idx < n && s[idx] == '0') idx++;
        
        while (idx < n) {
            if (isdigit(s[idx])) {
                int cur = s[idx] - '0';
                if (sign == 1 && ((ans == -214748364 && cur > 7) || ans < -214748364)) return INT_MAX;
                if (sign == -1 && ((ans == -214748364 && cur == 9) || ans < -214748364)) return INT_MIN;
                ans = ans * 10 - cur;
            } else break;
            idx++;
        }
        
        return -sign * ans;
    }
};