class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int num: nums) {
            maxVal = max(maxVal, num);
        }
        UnionFind uf(maxVal + 1);
        maxVal = (int)sqrt(maxVal) + 1;
        for (int num: nums) {
            for (int fac = 2; fac < min(num, maxVal); fac++) {
                if (num % fac == 0) {
                    uf.merge(num, fac);
                    uf.merge(num, num / fac);
                }    
            }
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for (int num: nums) {
            int t = uf.findSet(num);
            mp[uf.findSet(num)]++;
            ans = max(ans, mp[uf.findSet(num)]);
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