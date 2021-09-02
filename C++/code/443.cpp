class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int pos = 0;
        int cnt = 1;
        while (i < n) {
            cnt = 1;
            while (i < n - 1 && chars[i] == chars[i + 1]) {
                cnt++;
                i++;
            }
            chars[pos++] = chars[i++];
            if (cnt > 1) {
                string s = to_string(cnt);
                for (char ch: s) chars[pos++] = ch;
            }
        }
        for (int i = 0; i < n - pos; i++) chars.pop_back();
        return pos;
    }
};