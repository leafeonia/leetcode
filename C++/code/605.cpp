class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int cnt = 0, n = flowerbed.size();
        for (int i = 0; i < n; i++) {
            if (flowerbed[i] == 1) continue;
            int valid = 0;
            valid += i == 0 ? 1 : flowerbed[i - 1] == 0;
            valid += i == n - 1 ? 1 : flowerbed[i + 1] == 0;
            if (valid == 2) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= k;
    }
};