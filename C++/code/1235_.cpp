class Solution {
public:
    struct Job {
        Job(int s, int e, int p): s(s), e(e), p(p) {}
        int s, e, p;
        bool operator < (Job& j) {return e < j.e;}
    };
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> v;
        int n = startTime.size();
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            Job j(startTime[i], endTime[i], profit[i]);
            v.push_back(j);
        }
        sort(v.begin(), v.end());
        dp[0] = v[0].p;
        for (int i = 1; i < n; i++) {
            int left = 0, right = i - 1;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (v[mid].e <= v[i].s) left = mid;
                else right = mid - 1;
            }
            dp[i] = max(dp[i - 1], v[i].p);
            if (v[left].e <= v[i].s) {
                dp[i] = max(dp[i], dp[left] + v[i].p);
            }
        }
        return dp[n - 1];
    }
};

// 0  1  2  3   4
// 20 20 90 150 150