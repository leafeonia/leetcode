class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        int n = dict.size();
        vector<int> cnt(n, 0);
        string ans;
        for (char ch: s) {
            for (int i = 0; i < n; i++) {
                if (ch == dict[i][cnt[i]]) {
                    if (cnt[i] == dict[i].length() - 1) {
                        if (dict[i].length() > ans.length() || (dict[i].length() == ans.length() && dict[i] < ans)) ans = dict[i];
                    }
                    else cnt[i]++;
                }
            }
        }
        return ans;
    }
};