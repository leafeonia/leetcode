class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int biggest = nums[0], smallest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = max({nums[i], biggest * nums[i], smallest * nums[i]});
            smallest = min({nums[i], biggest * nums[i], smallest * nums[i]});
            biggest = temp;
            ans = max(ans, biggest);
        }
        return ans;
    }
};

//       2  3  -2  4    -1
// max   2  6  -2  4    48
// min   2  6  -12 -48  -4