class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> s;
        int m = grid.size();
        int n = grid[0].size();
        for (int r = 0; r <= (min(m, n) - 1)/ 2; r++) {
            for (int i = r; i < m - r; i++) {
                for (int j = r; j < n - r; j++) {
                    int sum = 0;
                    if (r == 0) sum = grid[i][j];
                    else {
                        for (int k = 0; k < r; k++) {
                            sum += grid[i - r + k][j + k];
                            sum += grid[i + k][j + r - k];
                            sum += grid[i + r - k][j - k];
                            sum += grid[i - k][j - r + k];
                        } 
                    }
                    if ((pq.size() < 3 && !s.count(sum))) {
                        pq.push(sum);
                        s.insert(sum);
                    } else if (sum > pq.top() && !s.count(sum)) {
                        s.erase(pq.top());
                        pq.pop();
                        pq.push(sum);
                        s.insert(sum);
                    }
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.insert(ans.begin(), pq.top());
            pq.pop();
        }
        return ans;
    }
};