class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int t = temperatures[i];
            while (!s.empty() && temperatures[s.top()] < t) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};