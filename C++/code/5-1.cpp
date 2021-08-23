class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int n = s.length();
        int rec = 1;
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > rec) {
                rec = right - left - 1;
                start = left + 1;
                end = right - 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > rec) {
                rec = right - left - 1;
                start = left + 1;
                end = right - 1;
            }
        }
        return s.substr(start, end - start + 1);
    }
};