class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 0, right = *max_element(ribbons.begin(), ribbons.end());
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            int sum = 0;
            for (int ribbon: ribbons) sum += ribbon / mid;
            if (sum < k) right = mid - 1;
            else left = mid;
        }
        return left;
    }
};