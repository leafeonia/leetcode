class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        nums.push_back(upper + 1);
        nums.insert(nums.begin(), lower - 1);
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            if (b - a <= 1) continue;
            if (b - a == 2) ans.push_back(to_string(a + 1));
            else ans.push_back(to_string(a + 1) + "->" + to_string(b - 1));
        }
        return ans;
    }
};

// X 76->98
// key: lower-1, upper+1