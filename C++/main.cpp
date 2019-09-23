#include<bits/stdc++.h>
using namespace std;
#define N 10002

int ans[N];
bool visited[N];
struct node{
    node(int vv = 0,int cc = 0){v = vv;c = cc;}
    int v,c;
};

bool operator < (node n1,node n2){
    return n1.c > n2.c;
}

struct edge{
    int to,weight;
    edge(int tto = 0,int wweight = 0){to = tto;weight = wweight;}
};

vector<edge> E[N];

void dijkstra(int start){
    for (int i = 0; i < N; ++i) {
        ans[i] = 0x3f3f3f3f;
    }
    memset(visited,false,sizeof(visited));
    ans[start] = 0;
    priority_queue<node> pq;
    while(!pq.empty())pq.pop();
    pq.push(node(start,0));
    node temp;
    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        int u = temp.v;
        if(visited[u]) continue;
        visited[u] = true;
        for (int i = 0; i < E[u].size(); ++i) {
            int next = E[u][i].to;
            int weight = E[u][i].weight;
            if(!visited[next] && ans[next] > ans[u]+weight ){
                ans[next] = ans[u] + weight;
                pq.push(node(next,ans[next]));
            }
        }
    }
}



int main(){
    freopen("in2.txt","r",stdin);
    int from,to;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&from,&to,&w);
        E[from].push_back(edge(to,w));
    }
    return 0;
}