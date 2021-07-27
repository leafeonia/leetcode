class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int m = nums1.size(), n = nums2.size();
        typedef pair<int, int> pi;
        auto compare = [&nums1, &nums2](pi a, pi b) {return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pi, vector<pi>, decltype(compare)> pq(compare);
        for (int i = 0; i < m; i++) {
            pq.push({i, 0});
        }
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            auto top = pq.top();
            pq.pop();
            vector<int> v{nums1[top.first], nums2[top.second]};
            if (top.second < n - 1) pq.push({top.first, top.second + 1});
            ans.push_back(v);
        }
        return ans;
    }
};
