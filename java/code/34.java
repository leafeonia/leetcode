class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;

        int left = -1, right = -1;
        while(start <= end){
            int middle = (start + end) / 2;
            if (nums[middle] == target && (middle == 0 || nums[middle-1] != target)){
                left = middle;
                break;
            }
            if (nums[middle] < target) start = middle + 1;
            else end = middle - 1;
        }
        start = 0;
        end = nums.length - 1;
        while(start <= end){
            int middle = (start + end) / 2;
            if (nums[middle] == target && (middle == nums.length - 1 || nums[middle+1] != target)){
                right = middle;
                break;
            }
            if (nums[middle] > target) end = middle - 1;
            else start = middle + 1;
        }
        int ans[] = {left, right};
        return ans;
    }
}