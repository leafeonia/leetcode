class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num: nums) mp[num]++;
        auto comp = [&](int a, int b) {return mp[a] > mp[b];};
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto pair: mp) {
            pq.push(pair.first);
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};