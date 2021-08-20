/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string a, string b) {
        int ret = 0;
        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i]) ret++;
        }
        return ret;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; i++) {
            string guess = wordlist[0];
            int record = 0;
            for (string word: wordlist) {
                int cnt = 0;
                for (string word2: wordlist) {
                    if (match(word, word2)) cnt++; 
                }
                if (cnt >= record) {
                    record = cnt;
                    guess = word;
                }
            }
            int ret = master.guess(guess);
            if (ret == 6) return;
            vector<string> newWordlist;
            for (string word: wordlist) {
                if (match(guess, word) == ret) newWordlist.push_back(word);
            }
            wordlist = newWordlist;
        }    
    }
};

// "abcdef" ["gggggg", "hhhhhh", "aggggg", "abcdef"]
// guess("gggggg") = 0 => if match("gggggg", any word in wordlist) > 0 then delete word from wordlist