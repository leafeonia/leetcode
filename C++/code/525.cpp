class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num) diff++;
            else diff--;
            if (mp.find(diff) != mp.end()) ans = max(ans, i - mp[diff]);
            else mp[diff] = i;
        }
        return ans;
    }
};