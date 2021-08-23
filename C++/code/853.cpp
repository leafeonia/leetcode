class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        typedef pair<int, int> pi;
        vector<pi> v;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), [](const pi& a, const pi& b) {return a.first > b.first;});
        int ans = 0;
        int idx = 0;
        while (idx < n) {
            double time = (double)(target - v[idx].first) / v[idx].second;
            idx++;
            while (idx < n && v[idx].first + time * v[idx].second >= target) idx++;
            ans++;
        }
        return ans;
    }
};