class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        map<int, vector<int>> mp;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for (auto& item: mp) {
            ans.insert(ans.end(), item.second.begin(), item.second.end());
        }
        return ans;
    }
};