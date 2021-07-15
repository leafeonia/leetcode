class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for (string s: equations) {
            if (s[1] == '=') {
                uf.merge(s[0] - 'a', s[3] - 'a');
            }
        }
        for (string s: equations) {
            if (s[1] == '!' && uf.findSet(s[0] - 'a') == uf.findSet(s[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
    
    class UnionFind {
    public:
        UnionFind(int n) {
            p.resize(n);
            r.resize(n, 0);
            for (int i = 0;i < n;i++) {
                p[i] = i;
            }
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
                if (r[px] == r[py])
                    r[px]++;
            }
        }
        
        vector<int> p;
        vector<int> r;
    };
};