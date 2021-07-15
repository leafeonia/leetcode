class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        vector<vector<int>> m_edges(n);
        for (auto& edge: edges) {
            degree[edge[1]]++;
            degree[edge[0]]++;
            m_edges[edge[1]].push_back(edge[0]);
            m_edges[edge[0]].push_back(edge[1]);
        }
        queue<int> q;
        for (int i = 0;i < n;i++) {
            if (degree[i] == 1)
                q.push(i);
        }
        int left = n;
        while(left > 2) {
            int sz = q.size();
            for (int i = 0;i < sz;i++) {
                int front = q.front();
                q.pop();
                degree[front] = 0;
                left--;
                for (int child: m_edges[front]) {
                    if (degree[child] == 0) continue;
                    degree[child]--;
                    if (degree[child] == 1)
                        q.push(child);
                }
            }
        }
        vector<int> ans;
        if (q.empty()) ans.push_back(0);
        else {
            while (!q.empty()) {
                ans.push_back(q.front());
                q.pop();
            }
        }
        return ans;
    }
};