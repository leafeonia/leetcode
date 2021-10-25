class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num: nums) mp[num]++;
        int ans = 0;
        for (auto& pair: mp) {
            if (k > 0 && mp.find(pair.first + k) != mp.end()) ans++;
            else if (k == 0 && pair.second > 1) ans++;
        }
        return ans;
    }
};