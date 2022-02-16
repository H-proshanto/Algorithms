#include <bits/stdc++.h>
#define ll long long
#define INF 1000000007
#define ii pair <int,int>
using namespace std;

const int maxn = 1e5 + 3;
vector <ii> adj[maxn];
ll dis[maxn];
int par[maxn];


void djkastra(ll u) {
    priority_queue <ii> q;
    dis[u] = 0;
    par[u] = -1;
    q.push(ii(0, u));

     while(!q.empty()){
        int u = q.top().second;
        q.pop();

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                par[v] = u;
                q.push(ii(-w, v));
            }
        }
    }
}


void solve() {
    int node, edge;

    cin >> node >> edge;

    for(int i = 0; i < edge; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        adj[node1].push_back({node2,weight});
        adj[node2].push_back({node1,weight});
    }

    for(int i = 0; i <= node; i++)dis[i] = INF;

    ll stNode;

    cin >> stNode;
    djkastra(stNode);

    for(int i = 0; i <= node; i++)cout << dis[i] << endl;
    for(int i = 0; i <= node; i++)adj[i].clear(), dis[i] = 0, par[i] = 0;
}

signed main() {
    int tst = 1;
    //int cs = 1;

    cin >> tst;


    while(tst--){
        //cout << "Case " << cs++ << ": " ;
        solve();
    }

    return 0;
}




