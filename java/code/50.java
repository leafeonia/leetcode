class Solution {
    public double myPow(double x, int n) {
        if (n < 0) x = 1 / x;
        boolean min = false;
        double x_origin = x;
        if (n == Integer.MIN_VALUE){
            n++;
            min = true;
        }
        n = Math.abs(n);

        /*
         * 2^21
         * 2^(10101)
         * */
        double ret = 1;
        while(n > 0){
            int bit = n & 1;
            if(bit == 1) ret *= x;
            x = x * x;
            n >>= 1;
        }
        if(min) ret *= x_origin;
        return ret;
    }
}