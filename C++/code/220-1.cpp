class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty() || nums.size() < 2 || k == 0) return false;
        multiset<int> s;
        for (int i = 0;i < nums.size();i++){
            auto iter = s.lower_bound((long)nums[i] - t);
            if (iter != s.end() && (long)(*iter + t) >= nums[i]) return true;
            s.insert(nums[i]);
            if (i >= k) s.erase(nums[i - k]);
        }
        return false;
    }
};
