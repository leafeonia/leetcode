class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        s.push(INT_MAX);
        for (int i = 0;i < nums2.size(); i++) {
            while (nums2[i] > s.top()) {
                int top = s.top();
                s.pop();
                mp[top] = nums2[i];
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for (int num: nums1) {
            if (!mp[num]) ans.push_back(-1);
            else ans.push_back(mp[num]);
        }
        return ans;
    }
};