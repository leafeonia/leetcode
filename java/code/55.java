class Solution {
    public boolean canJump(int[] nums) {
        boolean available[] = new boolean[nums.length];
        available[0] = true;
        int record = 0;
        for (int i = 0;i < nums.length;i++){
            if (!available[i]) return false;
            if (i + nums[i] >= nums.length - 1) return true;
            if (i + nums[i] > record){
                for (int j = record + 1;j <= i + nums[i];j++) available[j] = true;
            }
        }
        return true;
    }
}