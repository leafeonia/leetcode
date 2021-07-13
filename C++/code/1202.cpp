class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UnionFind uf(n);
        for (auto& pair: pairs) {
            uf.unite(pair[0], pair[1]);
        }
        unordered_map<int, vector<char>> mp;
        for (int i = 0;i < n;i++) {
            mp[uf.findSet(i)].push_back(s[i]);
        }
        for (auto& item: mp) {
            sort(item.second.begin(), item.second.end(), greater<char>());
        }
        for (int i = 0;i < n;i++) {
            s[i] = mp[uf.findSet(i)].back();
            mp[uf.findSet(i)].pop_back();
        }
        return s;
    }
    
private: 
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
        
        void unite(int x, int y) {
            int px = findSet(x);
            int py = findSet(y);
            if (px == py) return;
            if (r[px] > r[py]) {
                p[py] = px;
            } else {
                p[px] = py;
                if (r[px] == r[py]) {
                    r[py]++;
                }
            }
        }
           
    private:
        vector<int> p; //parent
        vector<int> r; //rank
    };
};