class Solution {
public:
    class UnionFind {
    public:
        vector<int> p, r;
        
        UnionFind(int n) {
            p.resize(n);
            r.resize(n, 0);
            for (int i = 0; i < n; i++) p[i] = i;
        }
        
        int findSet(int x) {
            return x == p[x] ? x : p[x] = findSet(p[x]);
        }
        
        void merge(int x, int y) {
            int px = findSet(x);
            int py = findSet(y);
            if (r[px] < r[py]) {
                p[px] = py;
            } else {
                p[py] = px;
                if (r[px] == r[py]) r[px]++;
            }
        }
    };
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        UnionFind uf(n);
        for (auto& edge: connections) {
            uf.merge(edge[0], edge[1]);
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(uf.findSet(i));
        }
        return s.size() - 1;
    }
};