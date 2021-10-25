class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        istringstream ss1(s1);
        string temp;
        while (getline(ss1, temp, ' ')) {
            mp[temp]++;
        }
        istringstream ss2(s2);
        while (getline(ss2, temp, ' ')) {
            mp[temp]++;
        }
        vector<string> ans;
        for (auto pair: mp) {
            if (pair.second == 1) ans.push_back(pair.first);
        }
        return ans;
    }
};