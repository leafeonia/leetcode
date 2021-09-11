class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int maxVal = 0;
        int maxIdx = -1;
        int swapStart = -1, swapEnd = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > maxVal) {
                maxVal = s[i];
                maxIdx = i;
            } else if (s[i] < maxVal) {
                swapEnd = maxIdx;
                swapStart = i;
            }
        }
        if (swapStart != -1) {
            swap(s[swapStart], s[swapEnd]);
        }
        return stoi(s);
    }
};

// 2345 -> 5342
// 3245 -> 5243
// 2355 -> 5352
// 3345 -> 5343
// 5342 -> 5432
// 983846