class Solution {
public:
    string ans;
    int n;
    
    unordered_map<string, vector<string>> edges;
    unordered_map<string, unordered_set<int>> visited;
    
    void dfs(string node, int cnt, string path) {
        if (!ans.empty()) return;
        if (cnt == n) {
            if (ans.empty()) ans = path;
            return;
        }
        for (int i = 0; i < edges[node].size(); i++) {
            if (visited[node].find(i) != visited[node].end()) continue;
            string next = edges[node][i];
            visited[node].insert(i);
            dfs(next, cnt + 1, path + next + "/");
            visited[node].erase(i);
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        for (auto& ticket: tickets) {
            edges[ticket[0]].push_back(ticket[1]);
        }
        for (auto& next: edges) {
            sort(next.second.begin(), next.second.end());
        }
        dfs("JFK", 0, "JFK/");
        istringstream ss(ans);
        string temp;
        vector<string> ans;
        while (getline(ss, temp, '/')) {
            ans.push_back(temp);
        }
        return ans;
    }
};