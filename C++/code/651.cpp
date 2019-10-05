class Solution {
public:
    int maxA(int N) {
        int a[52];
        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
        for(int i = 4;i <= N;i++){
            a[i] = max(2 * a[i-3], a[i-1] + (a[i-1] - a[i-2]));
            for(int j = i-4;j > max(0, i-7);j--){
                a[i] = max(a[i], (i - j - 1) * a[j]);
            }
        }
        return a[N];
    }
};