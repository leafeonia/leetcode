class Solution {
public:
    bool judgeSquareSum(int c) {
        int square = (int)sqrt(c);
        if (square*square == c) return true;
        for (int i = 1;i <= square;i++){
            int left = c - i * i;
            int s2 = (int)sqrt(left);
            if (s2 * s2 == left) return true;
        }
        return false;
    }
};
