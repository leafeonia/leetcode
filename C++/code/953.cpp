class Solution {
public:
    bool compare(string a, string b) {
        for (int i = 0; i < min(a.length(), b.length()); i++) {
            if (mp[a[i]] > mp[b[i]]) return false;
            if (mp[a[i]] < mp[b[i]]) return true;
        }
        if (a.length() > b.length()) return false;
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < 26; i++) mp[order[i]] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i + 1])) return false;
        }    
        return true;
    }
    
    unordered_map<char, int> mp;
};