class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        preSum.push_back(0);
        for (int num: nums) {
            sum += num;
            preSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
    
    vector<int> preSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */