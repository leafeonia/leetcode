class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string s: strs) {
            vector<int> cnt(26, 0);
            for (char ch: s) cnt[ch - 'a']++;
            string key;
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    key += 'a' + i;
                }
            }
            mp[key].push_back(s);
        }
        for (auto& pair: mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};