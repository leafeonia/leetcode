class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;
        while(left != right){
            ans = max(ans, (right - left) * min(height[left], height[right]));
            if(height[left] <= height[right]) left++;
            else right--;
        }
        return ans;
    }
};
//
// Created by maoym on 2019/9/5.
//

