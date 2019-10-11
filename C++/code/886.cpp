class Solution {
public:
    vector<vector<int>> graph;
    bool ans = true;
    vector<int> color; 
    vector<bool> visited; 
    void dfs(int cur,int c){
        visited[cur] = true;
        if(color[cur] != 0) {
            if(color[cur] != c) ans = false;
            return;
        }
        color[cur] = c;
        for(auto next: graph[cur]) dfs(next,-c);
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(N+1);
        color = vector<int>(N+1,0);
        visited = vector<bool>(N+1,false);
        for(auto relation: dislikes){
            graph[relation[0]].push_back(relation[1]);
            graph[relation[1]].push_back(relation[0]);
        }
        for(int i = 1;i <= N;i++){
            if(!visited[i]) dfs(i,1);
        }
        return ans;
    }
};