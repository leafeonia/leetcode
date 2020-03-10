class Solution {
public:
    map<string, bool> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(mp.find(s) != mp.end()) {
            return mp[s];
        }
        if(s.empty()) return true;
        for(auto word: wordDict){
            if(s.substr(0, word.length()) == word){
                if(wordBreak(s.substr(word.length()), wordDict)){
                    mp[s] = true;
                    return true;
                }
            }
        }
        mp[s] = false;
        return false;
    }
};