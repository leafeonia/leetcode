class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int leftMax = height[0], rightMax = height[n - 1];
        int left = 0, right = n - 1;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                ans += leftMax - height[left++];
                leftMax = max(leftMax, height[left]);
            } else {
                ans += rightMax - height[right--];
                rightMax = max(rightMax, height[right]);
            }
        }
        return ans;
    }
};