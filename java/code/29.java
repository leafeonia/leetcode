class Solution {

    public int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        if(dividend == Integer.MIN_VALUE && divisor == 1) return Integer.MIN_VALUE;
        if(dividend == Integer.MIN_VALUE && divisor == Integer.MIN_VALUE) return 1;
        if(dividend == 0 || divisor == Integer.MIN_VALUE) return 0;
        boolean sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        int ans = 0;
        if(dividend < 0) dividend = -dividend;
        if(divisor < 0) divisor = -divisor;
        int num = divisor;
        int cnt = 1;
        while(dividend - divisor >= 0){
            if (dividend - num > 0){
                dividend -= num;
                ans += cnt;
                num = num + num;
                cnt = cnt + cnt;
            }
            else{
                num = divisor;
                cnt = 1;
                ans += 1;
                dividend -= num;
            }
        }
        return (sign ? ans : -ans);
    }
}