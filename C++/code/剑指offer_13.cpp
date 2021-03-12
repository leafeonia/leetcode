class Solution {
public:
    vector<vector<int>> visited;
    //int visited[102][102];
    int movingCount(int m, int n, int k) {
        x_max = m;
        y_max = n;
        visited.resize(m);
        for(auto& line: visited) line.resize(n);
        count = 0;
        dfs(0, 0, k);
        return count;
    }
private:
    int x_max, y_max, count;
    int val(int num){
        if (num < 10) return num;
        return num / 10 + num % 10;
    }
    void dfs(int x, int y, int k){
        if (val(x) + val(y) > k || x < 0 || x >= x_max || y < 0 || y >= y_max || visited[x][y]) return;
        count++;
        visited[x][y] = 1;
        dfs(x+1, y, k);
        dfs(x-1, y, k);
        dfs(x, y-1, k);
        dfs(x, y+1, k);
    }
};
