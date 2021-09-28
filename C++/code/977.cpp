class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int left = 0;
        int right = n - 1;
        for(int i = n - 1;i >= 0;i--){
            int leftval = nums[left] * nums[left];
            int rightval = nums[right] * nums[right];
            if (leftval >= rightval) {
                answer[i] = leftval;
                left++;
            } else {
                answer[i] = rightval;
                right--;
            }
        }
        return answer;
    }
};