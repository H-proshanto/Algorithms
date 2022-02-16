#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
using namespace std;

const int maxn = 1e5 + 3;
vector <int> adj[maxn];
int vis[maxn],in[maxn],low[maxn],cnt = 0;
unordered_map<int,int> isartpoint;

void articulation_point(int node,int par) {
    vis[node] = 1;
    in[node] = low[node] = ++cnt;
    int childrens = 0;

    for(int child : adj[node]) {
        if(child==par)continue;
        if(vis[child]) {
            low[node] = min(low[node],in[child]);
        }
        else {
            articulation_point(child,node);
            low[node] = min(low[child],low[node]);
            if(low[child] >= in[node] && par != -1)
               isartpoint[node] = 1;
            childrens++;
        }
}
    if(par == -1 && childrens > 1)
        isartpoint[node] = 1;
}



void solve() {
    int node, edge;

    cin >> node >> edge;

    for(int i = 0; i < edge; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    ll stNode;

    cin >> stNode;
    articulation_point(stNode,-1);

    for(int i = 0; i <= node; i++)cout << i << "  " << isartpoint[i] << endl;

    for(int i = 0; i <= node; i++)
        adj[i].clear(), vis[i] = 0, in[i] = 0, low[i] = 0;

    isartpoint.clear();
    cnt = 0;
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




