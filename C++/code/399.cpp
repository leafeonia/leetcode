class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_map<string, int> state;
    
    double dfs(string node, double value, string target) {
        if (graph[node].empty() || state[node] == 1) return -1.0;
        if (node == target)
            return value;
        state[node] = 1;
        for (auto& next: graph[node]) {
            double ret = dfs(next.first, value * next.second, target);
            if (ret != -1.0) {
                state[node] = 0;
                return ret;
            }
        }
        state[node] = 0;
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> ans;
        for (int i = 0;i < n;i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        for (auto& query: queries) {
            ans.push_back(dfs(query[0], 1.0, query[1]));
        }
        return ans;
    }
};