class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE, cur = 0;
        for (int i = 0;i < nums.length;i++){
            if(cur > 0) cur = cur + nums[i];
            else cur = nums[i];
            if(cur > ans) ans = cur;
        }
        return ans;
    }
}