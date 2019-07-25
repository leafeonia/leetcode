#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102][102];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(!m) return 0;
        int n = obstacleGrid[0].size();
        memset(dp,0, sizeof(dp));
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(i == 1 && j == 1) continue;
                if(obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution solution;
    vector<vector<int>> v;
    int t1[] = {0,0,0};
    int t2[] = {0,0,1};
    vector<int> a(t1,t1+3);
    vector<int> c(a);
    vector<int> b(t2,t2+3);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    cout << solution.uniquePathsWithObstacles(v);
    return 0;
}