class Solution {
public:
    class Unionfind {
    public:    
        Unionfind(int n) {
            r.resize(n * n, 1);
            p.resize(n * n);
            for (int i = 0; i < n * n; i++) {
                p[i] = i;
            }
        }
        
        int find(int n) {
            if (p[n] == n) return n;
            else return p[n] = find(p[n]);
        }
        
        void merge(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;
            if (r[pa] < r[pb]) {
                p[pa] = pb;
                r[pb] += r[pa];
            } else {
                p[pb] = pa;
                r[pa] += r[pb];
            }
        }
        
        int getSize(int n) {
            return r[find(n)];
        }
    
    private:
        vector<int> r;
        vector<int> p;
    };
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dires{{1,0}, {0,1}, {-1, 0}, {0, -1}};
        Unionfind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                for (auto dire: dires) {
                    int x = i + dire[0];
                    int y = j + dire[1];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (grid[x][y]) uf.merge(i * n + j, x * n + y);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                unordered_map<int, int> temp;
                for (auto dire: dires) {
                    int x = i + dire[0];
                    int y = j + dire[1];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (grid[x][y]) temp[uf.find(x * n + y)] = uf.getSize(x * n + y);
                }
                int tot = 0;
                for (auto ele: temp) tot += ele.second;
                ans = max(ans, tot + 1);
            }
        }
        
        if (ans == -1) return n * n;
        return ans;
    }
};