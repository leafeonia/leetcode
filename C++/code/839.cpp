class Solution {
public:
    bool swapable(string a, string b) {
        if (a == b) return true;
        int cnt = 0;
        for (int i = 0;i < a.length();i++) {
            if (a[i] != b[i]) cnt++;
            if (cnt > 2) return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                if (uf.findSet(i) == uf.findSet(j)) continue;
                if (swapable(strs[i], strs[j])) 
                    uf.merge(i, j);
            }
        }
        int ans = 0;
        for (int i = 0;i < n;i++) {
            if (uf.findSet(i) == i){
                ans++;
            }
        }
        return ans;
    }

private:
    class UnionFind {
        public: UnionFind(int n) {
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