class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX, n = points.size();
        unordered_map<int, set<int>> mp;
        for (auto& point: points) {
            mp[point[0]].insert(point[1]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto& p1 = points[i];
                auto& p2 = points[j];
                if (p1[0] == p2[0] || p1[1] == p2[1]) continue;
                if (mp[p1[0]].find(p2[1]) != mp[p1[0]].end() && mp[p2[0]].find(p1[1]) != mp[p2[0]].end()) {
                    ans = min(ans, abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};