class Solution {
public:
    vector<vector<int>> ans;
    vector<int> used;
    vector<int> cur;
    int n;
    
    void dfs(vector<int>& nums) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n;i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums);
            cur.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        used.resize(n, 0);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ans;
    }
};

// 1 1 2 3 3
// 1  2  3
// 