class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<string> words;
        string word = "";
        for(char c: s){
            if(c != ' ') word += c;
            else{
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);
        int index = 0;
        for(int i = words.size() - 1;i >= 0;i--){
            for(auto c: words[i]){
                s[index++] = c;
            }
            if(i) s[index++] = ' ';
        }
    }
};