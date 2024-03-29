class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int stick: sticks) pq.push(stick);
        int ans = 0;
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        return ans;
    }
};