class Solution {
public:
    vector<int> partitionLabels(string s) {
        typedef pair<int,int> pi;
        vector<int> left(26, -1);
        vector<int> right(26, -1);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            right[s[i] - 'a'] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            left[s[i] - 'a'] = i;
        }
        vector<pi> v;
        for (int i = 0; i < 26; i++) {
            if (left[i] != -1) {
                v.push_back({left[i], right[i]});
            }
        }
        sort(v.begin(), v.end(), [](pi a, pi b){return a.first < b.first;});
        vector<int> ans;
        pi cur = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > cur.second) {
                ans.push_back(cur.second - cur.first + 1);
                cur = v[i];
            } else {
                cur.second = max(cur.second, v[i].second);
            }
        }
        ans.push_back(cur.second - cur.first + 1);
        return ans;
    }
};