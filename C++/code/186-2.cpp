class Solution {
public:
    void reverseWords(vector<char>& s) {
        int start = 0;
        int fin;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' ' || i == s.size() - 1){
                fin = i - 1;
                if(i == s.size() - 1) fin++;
                for(int j = 0;j <= (fin - start) / 2;j++){
                    swap(s[start + j], s[fin - j]);
                }
                start = i + 1;
            }
        }
        for(int i = 0;i < s.size() / 2;i++){
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};