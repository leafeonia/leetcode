class Solution {
public:
    vector<int> partitionLabels(string s) {
        typedef pair<int,int> pi;
        vector<int> right(26, -1);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            right[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int rangeEnd = 0, rangeBegin = 0;
        for (int i = 0; i < n; i++) {
            rangeEnd = max(rangeEnd, right[s[i] - 'a']);
            if (rangeEnd == i) {
                ans.push_back(rangeEnd - rangeBegin + 1);
                rangeBegin = i + 1;
            }
        }
        return ans;
    }
};