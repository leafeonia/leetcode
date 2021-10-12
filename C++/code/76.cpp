class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dicT;
        unordered_map<char, int> found;
        for (char ch: t) dicT[ch]++;
        int required = t.size(), left = 0;
        int ansLeft = -1, ansRight = 100000;
        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            if (dicT.find(ch) != dicT.end()) {
                found[ch]++;
                if (found[ch] <= dicT[ch]) required--; 
            }
            while (required == 0) {
                if (right - left < ansRight - ansLeft) {
                    ansLeft = left;
                    ansRight = right;
                }
                if (dicT.find(s[left]) != dicT.end()) {
                    found[s[left]]--;
                    if (found[s[left]] < dicT[s[left]]) required++;
                }
                left++;
            }
        }
        return ansLeft != -1 ? s.substr(ansLeft, ansRight - ansLeft + 1) : "";
    }
};