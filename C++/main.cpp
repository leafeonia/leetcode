#include <bits/stdc++.h>
using namespace std;
#define MAXN 1002
struct union_find{
    int r[MAXN]; //rank
    int f[MAXN]; //father

    void make_set(int i){
        r[i] = 0;
        f[i] = i;
    }

    void link(int x,int y){
        if(r[x] > r[y]) {
            f[y] = x;

        }
        else{
            f[x] = y;
            if(r[x] == r[y]) r[y]++;
        }
    }
    int find_set(int x){
        if(x != f[x]) {
            f[x] = find_set(f[x]);
        }

        return f[x];

    }
    void unite(int x,int y){
        int a = find_set(x);
        int b = find_set(y);
        link(a,b);
    }
}uf;

struct edge{
    edge(int f,int t,int w){from = f;to = t;weight = w;}
    int from,to,weight;
};

bool operator > (const edge e1, const edge e2){
    return e1.weight > e2.weight;
}

priority_queue<edge,vector<edge>,greater<edge> > pq;

int main() {
    ios::sync_with_stdio(false);
    freopen("in2.txt","r",stdin);
    int T;
    cin >> T;
    bool used[1002][1002];
    for(int kase = 1;kase <= T;kase++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            uf.make_set(i);
        }
        while(!pq.empty()) pq.pop();
        memset(used, false, sizeof(used));
        for (int i = 0; i < m; ++i) {
            int f, t;
            cin >> f >> t;
            used[f][t] = used[t][f] =true;
            pq.push(edge(f, t, 1));
            pq.push(edge(t, f, 1));
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(!used[i][j]) {
                    pq.push(edge(i, j, 2));
                    pq.push(edge(j, i, 2));
                }
            }
        }
        int cnt = 0;
        int ans = 0;
        while (!pq.empty() && cnt != n - 1) {
            edge temp = pq.top();
            pq.pop();
            if (uf.find_set(temp.from) != uf.find_set(temp.to)) {
                cnt++;
                ans += temp.weight;
                uf.unite(temp.from, temp.to);
            }
        }
        cout << "Case #" << kase << ": " << ans << endl;
    }
    return 0;
}