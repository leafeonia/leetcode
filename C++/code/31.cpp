class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int index = nums.size() - 2;
        while(index >= 0 && nums[index] >= nums[index + 1]){
            index--;
        }
        if(index < 0){
            for(int i = 0;i < nums.size() / 2;i++){
                swap(nums[i], nums[nums.size() - 1 - i]);
            }
            return;
        }
        int index2 = index + 1;
        int record = 0x3f3f3f3f;
        for(int j = index + 1;j < nums.size();j++){
            if(nums[j] > nums[index] && nums[j] <= record){
                index2 = j;
                record = nums[j];
            }
        }
        swap(nums[index2], nums[index]);
        for(int i = 0;i < (nums.size() - 1 - index) / 2;i++){
            swap(nums[index + 1 + i], nums[nums.size() - 1 - i]);
        }
    }
};