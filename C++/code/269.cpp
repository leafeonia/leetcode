class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<int> indeg(26, 0);
        vector<set<int>> s(26);
        vector<int> used(26, 0);
        for (string word: words) {
            for (char ch: word) {
                used[ch - 'a'] = 1;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            int idx = 0;
            string word1 = words[i];
            string word2 = words[i + 1];
            if (word1.length() > word2.length() && word1.substr(0, word2.length()) == word2) return "";
            while (idx < min(word1.length(), word2.length())) {
                int ch1 = word1[idx] - 'a';
                int ch2 = word2[idx] - 'a';
                if (ch1 != ch2) {
                    if (s[ch1].find(ch2) != s[ch1].end()) break;
                    indeg[ch2]++;
                    s[ch1].insert(ch2);
                    break;
                }
                idx++;
            }
        }
        bool changed = true;
        string ans;
        while (changed) {
            changed = false;
            for (int i = 0; i < 26; i++) {
                if (indeg[i] == 0 && used[i]) {
                    ans += 'a' + i;
                    for (int next: s[i]) {
                        indeg[next]--;
                    }
                    changed = true;
                    indeg[i] = -1;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (indeg[i] > 0) return "";
        }
        return ans;
    }
};