class Solution {
public:
    string generateLine(vector<string>& cur, int maxWidth, bool last) {
        string ret = "";
        if (last || cur.size() == 1) {
            int le = 0;
            for (int i = 0; i < cur.size() - 1; i++) {
                ret += cur[i] + " ";
                le += cur[i].length() + 1;
            }
            ret += cur[cur.size() - 1];
            le += cur[cur.size() - 1].length();
            for (int i = 0; i < maxWidth - le; i++) ret += " ";
        } else {
            int totLength = 0;
            for (string s: cur) totLength += s.length();
            int totBlank = maxWidth - totLength;
            int avgBlank = totBlank / (cur.size() - 1);
            int extra = totBlank % (cur.size() - 1);
            for (int i = 0; i < extra; i++) {
                ret += cur[i];
                for (int j = 0; j < avgBlank + 1; j++) ret += " ";
            }
            for (int i = extra; i < cur.size() - 1; i++) {
                ret += cur[i];
                for (int j = 0; j < avgBlank; j++) ret += " ";
            }
            ret += cur[cur.size() - 1];
        }
        return ret;    
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> cur;
        int curlength = 0;
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string word = words[i];
            if (curlength + word.length() > maxWidth) {
                ans.push_back(generateLine(cur, maxWidth, false));
                cur.clear();
                cur.push_back(word);
                curlength = word.length() + 1;
            } else {
                cur.push_back(word);
                curlength += 1 + word.length();
            }
        }
        string word = words[n - 1];
        if (curlength + word.length() > maxWidth) {
            ans.push_back(generateLine(cur, maxWidth, false));
            cur.clear(); 
        } 
        cur.push_back(word);
        ans.push_back(generateLine(cur, maxWidth, true));
        return ans;
    }
};