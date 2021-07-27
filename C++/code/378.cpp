class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef pair<int, int> pi;
        int m = matrix.size();
        int n = matrix[0].size();
        auto comp = [&matrix](pi a, pi b) {return matrix[a.first][a.second] > matrix[b.first][b.second];};
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        for (int i = 0; i < m; i++) {
            pq.push({i, 0});
        }
        for (int i = 1; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            if (top.second < n - 1) {
                pq.push({top.first, top.second + 1});
            }
        }
        return matrix[pq.top().first][pq.top().second];
    }
};