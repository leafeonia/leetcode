class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        int maxVal = 0, n = s.length(), maxChar = 0;
        for (char ch: s) {
            cnt[ch - 'a']++;
            if (cnt[ch - 'a'] > maxVal) {
                maxVal = cnt[ch - 'a'];
                maxChar = ch - 'a';
            }
        }
        if (maxVal > (s.length() + 1) / 2) return "";
        string ans(n, ' ');
        int idx = 0;
        while (cnt[maxChar]) {
            ans[idx] = maxChar + 'a';
            idx += 2;
            cnt[maxChar]--;
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i]) {
                if (idx >= n) idx = 1;
                while (ans[idx] != ' ') {
                    idx++;
                    if (idx == n) idx = 1;
                }
                ans[idx] = i + 'a';
                idx += 2;
                cnt[i]--;
            }
        }
        return ans;
    }
};

// n = 3 maxVal <= 2
// n = 4, maxVal <= 2 