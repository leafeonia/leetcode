class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string s: words) {
            mp[s]++;
        }
        typedef pair<string, int> pi;
        auto comp = [](pi a, pi b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        };
        
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        
        for (auto ele: mp) {
            pq.push({ele.first, ele.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
};