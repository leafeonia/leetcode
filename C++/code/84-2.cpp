class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(0);
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n = heights.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            while (heights[s.top()] > heights[i]) {
                int height = heights[s.top()];
                s.pop();
                ans = max(ans, height * (i - s.top() - 1));
            }
            s.push(i);
        }
        return ans;
    }
};