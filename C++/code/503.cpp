class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[i % n] > nums[s.top() % n]) {
                ans[s.top() % n] = nums[i % n];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};