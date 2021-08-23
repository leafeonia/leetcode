class Solution {
public:
    /*int ans, m_target;
    vector<vector<int>> m_stations;
    
    void dfs(int stationId, int fuel, int stop) {
        int pos = stationId == -1 ? 0 : m_stations[stationId];
        if (pos + fuel >= m_target) {
            ans = min(ans, stop);
            return;
        }
        for (int next = stationId + 1; next < m_stations.size(); i++) {
            if (pos + fuel < m_stations[next][0]) break;
            dfs(next, fuel - (m_stations[next][0] - pos), stop);
            dfs(next, fuel - (m_stations[next][0] - pos) + m_stations[next][1], stop + 1);
        }
    }*/
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<int> start{0, 0};
        vector<int> dest{target, 0};
        stations.push_back(start);
        stations.push_back(dest);
        sort(stations.begin(), stations.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        int n = stations.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        
        dp[0][0] = startFuel;
        for (int col = 1; col < n; col++) {
            for (int line = 0; line <= col; line++) {
                int dist = stations[col][0] - stations[col - 1][0];
                if (line == 0) {
                    if (dp[line][col - 1] >= dist) dp[line][col] = dp[line][col - 1] - dist;
                }
                else {
                    if (dp[line - 1][col - 1] >= dist) dp[line][col] = dp[line - 1][col - 1] - dist + stations[col][1];
                    if (dp[line][col - 1] >= dist) dp[line][col] = max(dp[line][col], dp[line][col - 1] - dist);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp[i][n - 1] >= 0) return i;
        }
        return -1;
    }
};

//      0  1  2   3                      4     5(stationId)
// 0    10 0  -   -                      -     -
// 1       60 50  40                     10    -
// 2          80  max(50-10+30,80-10)=70 50    10
// 3              100                    80    40
// 4                                     110   70
// stop