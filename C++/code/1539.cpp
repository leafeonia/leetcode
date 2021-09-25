class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] - mid - 1 >= k) right = mid - 1;
            else left = mid;
        }
        return arr[left] + k - (arr[left] - left - 1);
    }
    
    // 1 2 3 5 8  k = 2
    // 1 5 7 11 12  k = 4 
};