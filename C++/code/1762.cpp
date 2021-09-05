class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int n = heights.size();
        int maxheight = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (heights[i] > maxheight) ans.push_back(i);
            maxheight = max(maxheight, heights[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};