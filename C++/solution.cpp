#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = INT_MAX;

    void dfs(vector<int>& tasks, vector<int>& used, int level, int idx, int sum) {
        if (used.size() == n) {
            ans = min(ans, level);
        }
        for (int i = idx; i < n; i++) {
            if (!used[i]) {
                if (sum + tasks[i] <= t) {
                    used[i] = 1;
                    dfs(tasks, used, level, i + 1, sum + tasks[i]);
                    used[i] = 0;
                } else {
                    used[i] = 1;
                    dfs(tasks, used, level + 1, 0, tasks[i]);
                    used[i] = 0;
                }

                //dfs(tasks, used, level, i + 1, sum);
            }
        }
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        t = sessionTime;
        n = tasks.size();
        vector<int> used(n, 0);
        dfs(tasks, used, 0, 0, 0);
        return ans;
    }

    int n;
    int t;
};