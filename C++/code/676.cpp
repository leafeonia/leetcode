class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for (string word: dictionary) {
            mp[word.length()].push_back(word);
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.length();
        for (string word: mp[n]) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (word[i] != searchWord[i]) cnt++;
            }
            if (cnt == 1) return true;
        }
        return false;
    }
    
    unordered_map<int, vector<string>> mp;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */