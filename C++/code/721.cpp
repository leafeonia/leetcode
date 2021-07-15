class Solution {
public:
    bool check(vector<string> a, vector<string> b) {
        if (a[0] != b[0]) return false;
        for (int i = 1;i < a.size();i++) {
            for (int j = 1;j < b.size();j++) {
                if (a[i] == b[j]) return true;
            }
        }
        return false;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email2name;
        unordered_map<string, int> email2id;
        UnionFind uf(10000);
        int id = 0;
        for (auto& account: accounts) {
            string name = account[0];
            for (int i = 1;i < account.size();i++) {
                string email = account[i];
                if (email2name.find(email) == email2name.end()) {
                    email2name[email] = name;
                }
                if (email2id.find(email) == email2id.end()) {
                    email2id[email] = id++;
                }
            }
        }
        for (auto& account: accounts) {
            int firstId = email2id[account[1]];
            for (int i = 2;i < account.size();i++) {
                uf.merge(firstId, email2id[account[i]]);
            }
        }
        unordered_map<int, set<string>> mp;
        for (auto& account: accounts) {
            for (int i = 1;i < account.size();i++) {
                string email = account[i];
                mp[uf.findSet(email2id[email])].insert(email); 
            }
        }
        vector<vector<string>> ans;
        for (auto& mailList: mp) {
            vector<string> v;
            for (string mail: mailList.second) {
                v.push_back(mail);
            }
            sort(v.begin(), v.end());
            v.insert(v.begin(), email2name[v[0]]);
            ans.push_back(v);
        }
        return ans;
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