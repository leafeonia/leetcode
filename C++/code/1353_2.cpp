class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int ans = 0, idx = 0, day = 0, n = events.size();
        while (!pq.empty() || idx < n) {
            if (pq.empty()) day = events[idx][0];
            while (idx < n && events[idx][0] == day) {
                pq.push(events[idx++][1]);
            }
            pq.pop();
            ans++;
            day++;
            while (!pq.empty() && pq.top() < day) pq.pop();
        }
        return ans;
    }
};