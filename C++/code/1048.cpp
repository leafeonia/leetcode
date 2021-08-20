class Solution {
public:
    bool isPred(string a, string b) {
        int diff = -1;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                diff = i;
                break;
            }
        }    
        if (diff == -1) return true;
        for (int i = diff; i < a.length(); i++) {
            if (a[i] != b[i + 1]) return false;
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){return a.length() < b.length();});
        int n = words.size();
        vector<int> maxlength(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[j].length() + 1 != words[i].length()) continue;
                if (isPred(words[j], words[i])) {
                    maxlength[i] = max(maxlength[i], maxlength[j] + 1);
                    ans = max(ans, maxlength[i]);
                }
            }
        }
        return ans;
    }
};