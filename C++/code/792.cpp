class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        vector<vector<string>> dict(26);
        for (string word: words) {
            dict[word[0] - 'a'].push_back(word);
        }
        for (char ch: s) {
            vector<string> temp;
            for (auto str: dict[ch - 'a']) {
                if (str.length() == 1) ans++;
                else {
                    if (str[1] != ch) dict[str[1] - 'a'].push_back(str.substr(1));
                    else temp.push_back(str.substr(1));
                }
            }
            dict[ch - 'a'].clear();
            for (string s: temp) dict[ch - 'a'].push_back(s);
        }
        return ans;
    }
};