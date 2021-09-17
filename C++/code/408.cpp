class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int a = 0, b = 0;
        while (b < abbr.length() && a < word.length()) {
            if (isalpha(abbr[b])) {
                if (word[a++] != abbr[b++]) return false;
            } else {
                if (abbr[b] == '0') return false;
                string num;
                while (isdigit(abbr[b])) {
                    num += abbr[b++];
                }
                a += stoi(num);
            }
        }
        return a == word.length() && b == abbr.length();
    }
};