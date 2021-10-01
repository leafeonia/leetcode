class Solution {
public:
    bool dfs(int i, int color) {
        if (v[i] != -1) {
            if (v[i] != color) return false;
            return true;
        }
        v[i] = color;
        for (int next: m_graph[i]) {
            if (!dfs(next, 1 - color)) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        v.resize(n, -1);
        m_graph = graph;
        for (int i = 0; i < n; i++) {
            if (v[i] == -1) {
                if (!dfs(i, 0)) return false;
            }
        }
        return true;
    }
    
    vector<vector<int>> m_graph;
    vector<int> v;
};