class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (string s: strings) {
            string key;
            for (int i = 1; i < s.length(); i++) {
                int diff = s[i] > s[i - 1] ? s[i] - s[i - 1] : 26 - (s[i - 1] - s[i]); 
                key += to_string(diff) + ",";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto ele: mp) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};