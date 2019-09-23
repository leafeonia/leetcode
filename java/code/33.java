class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        // 4 5 6 7 0 1 2

        // 0 1 2 4 5 6 7

        // 7 0 1 2 4 5 6

        // 6 7 0 1 2 4 5
        while(start <= end){
            if(start + 1 == end){
                if(nums[start] == target) return start;
                if(nums[end] == target) return end;
                return -1;
            }
            int middle = (start + end)/2;
            if(nums[middle] == target) return middle;
            if(nums[middle] < target) {
                if((nums[end] > nums[middle] && nums[end] >= target) || (nums[end] < nums[middle] && target > nums[middle])) start = middle + 1;
                else end = middle - 1;
            }
            else{
                if((nums[start] < nums[middle] && nums[start] <= target) ||
                        (nums[start] > nums[middle])) end = middle - 1;
                else start = middle + 1;
            }
        }
        return -1;

    }
}