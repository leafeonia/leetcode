#include <bits/stdc++.h>
using namespace std;


int main(){
    int uniquePaths(int m, int n) {
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(i == 1 && j == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
    return 0;
}