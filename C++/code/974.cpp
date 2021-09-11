class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for (int num: nums) {
            sum += num;
            ans += mp[(sum % k + k) % k];
            mp[(sum % k + k) % k]++;
        }
        return ans;
    }
};