class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int index = 0;
        while(index < nums.size()){
            while(nums[index] != index){
                if(nums[nums[index]] == nums[index]) return nums[index];
                swap(nums[index], nums[nums[index]]);
            }
            index++;
        }
       
        return -1;
    }
};