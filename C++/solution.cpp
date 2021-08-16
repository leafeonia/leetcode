#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        UnionFind uf(row, col);
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> dires {{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
        for (int i = 0; i < cells.size(); i++) {
            auto& cell = cells[i];
            int r = cell[0] - 1;
            int c = cell[1] - 1;
            visited[r][c] = 1;
            for (auto dire: dires) {
                int r2 = r + dire[0];
                int c2 = c + dire[1];
                if (r2 < 0 || r2 >= row || c2 < 0 || r2 >= col) continue;
                if (visited[r2][c2]) {
                    if (uf.merge(r2 * col + c2, r * col + c)) return i;
                }
            }
        }
        return row * col - 1;
    }

    class UnionFind {
    public:
        UnionFind(int row, int col) {
            int n = row * col;
            m_row = row;
            m_col = col;
            p.resize(n);
            r.resize(n, 0);
            sets.resize(n);
            for (int i = 0;i < n;i++) {
                p[i] = i;
                sets[i].insert(i % col);
            }
        }

        int findSet(int x) {
            return x == p[x] ? x : p[x] = findSet(p[x]);
        }

        bool merge(int x, int y) {
            int px = findSet(x);
            int py = findSet(y);
            if (px == py) return false;
            if (r[px] < r[py]) {
                p[px] = py;
                for (auto ele: sets[px]) sets[py].insert(ele);
                if (sets[py].size() == m_col) return true;
            } else {
                p[py] = px;
                if (r[px] == r[py])
                    r[px]++;
                for (auto ele: sets[py]) sets[px].insert(ele);
                if (sets[px].size() == m_col) return true;
            }
            return false;
        }

        int m_row;
        int m_col;
        vector<int> p;
        vector<int> r;
        vector<set<int>> sets;
    };
};