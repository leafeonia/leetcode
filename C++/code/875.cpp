class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1;
        for (int num: piles) right = max(right, num);
        int n = piles.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int time = 0;
            for (int num: piles) time += (num - 1) / mid + 1;
            if (time > h) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};