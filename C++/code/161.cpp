class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (s == t || abs(m - n) > 1 || (!m && !n)) return false;
        int a = 0, b = 0;
        bool diff = false;
        while (a < m && b < n) {
            if (s[a] != t[b]) {
                if (m == n) {
                    a++;
                    b++;
                } else if (m < n) {
                    b++;
                } else a++;
                if (!diff) diff = true;
                else return false;
            } else {
                a++;
                b++;
            }
            
        }
        return true;
    }
};