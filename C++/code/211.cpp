class WordDictionary {
public:
    
    class Trie {
    public:
        
        class TrieNode {
        public:
            TrieNode() {
                next = vector<TrieNode*> (26, nullptr);
                isEnd = false;
            }
            
            vector<TrieNode*> next;
            bool isEnd;
        };
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string s) {
            TrieNode* cur = root;
            for (char ch: s) {
                if (!cur->next[ch - 'a']) {
                    cur->next[ch - 'a'] = new TrieNode();
                }
                cur = cur->next[ch - 'a'];
            }
            cur->isEnd = true;
        }
        
        bool search(string s) {
            return search(s, 0, root);
        }
        
        bool search(string s, int idx, TrieNode* cur) {
            if (!cur) return false;
            if (idx == s.length()) return cur->isEnd;
            if (s[idx] == '.') {
                for (auto nxt: cur->next) {
                    if (nxt && search(s, idx + 1, nxt)) return true;
                }
                return false;
            } else {
                if (cur->next[s[idx] - 'a'])  return search(s, idx + 1, cur->next[s[idx] - 'a']);
                return false;
            }
        }
        
        TrieNode* root;
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
    
    Trie* trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */