class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnt(256, 0);
        int num = 0, left = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (cnt[s[i]] == 0) num++;
            cnt[s[i]]++;
            while (num > k) {
                if (cnt[s[left]] == 1) num--;
                cnt[s[left++]]--;
            }
            ans = max(i - left + 1, ans);
        }
        return ans;
    }
};