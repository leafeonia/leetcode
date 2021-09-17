class Solution {
public:
    bool canPermutePalindrome(string s) {
        int bit = 0;
        for (char ch: s) {
            bit ^= (1 << (ch - 'a'));
        }
        return bit == 0 || (bit & (bit - 1)) == 0;
    }
};