class Solution {
public:
    int findNthDigit(int n) {
        long long base = 9;
        int digit = 1;
        while (n > base * digit) {
            n -= base * digit;
            base *= 10;
            digit++;
        }
        
        long long num = pow(10, digit - 1) + (n - 1) / digit;
        return to_string(num)[(n - 1) % digit] - '0';
        
        // 200 1-99:189 100 101 102 103 
    }
};