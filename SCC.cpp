#include <bits/stdc++.h>
#define ii pair <int,int>
#define pb push_back
using namespace std;

const int maxn = 1e5 + 69;
int sc_comp;
vector<int> adj[maxn];
vector<int> backadj[maxn];
int vis[maxn],cnt = 0;
vector <ii> topo;
vector <int> scclist[maxn];
int in[maxn],out[maxn];

void dfs(int node) {
    vis[node] = 1;
    in[node] = ++cnt;
    for(int child : adj[node]) {
        if(!vis[child])
            dfs(child);
    }
    out[node] = ++cnt;
}

void scc(int node) {
    vis[node] = 1;
    for(int child : backadj[node]) {
        if(!vis[child]) {
            scclist[sc_comp].pb(child);
            scc(child);
        }
    }
}

void solve() {
    int node,edge;
    cin >> node >> edge;

    for(int i = 1;i <= edge; i++) {
        int x,y;
        cin >> x >> y ;
        adj[x].push_back(y);
        backadj[y].push_back(x);
    }

    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= node; i++) {
        if(!vis[i]){
            dfs(i);
        }
    }

    for(int i = 1; i <= node; i++) {
       topo.push_back({out[i],i});
    }
    sort(topo.begin(),topo.end());

    memset(vis,0,sizeof(vis));

    sc_comp = 0;
    for(int i = topo.size() - 1; i >= 0; i--) {
        int x = topo[i].second;
        if(!vis[x]){
            scclist[sc_comp].pb(x);
            scc(x);
            sc_comp++;
        }
    }
    /*
    ///how many strongly connected components !
    cout << sc_comp << endl;

    ///The list of SCC
    for(int i = 0;i <= sc_comp; i++) {
        for(int x : scclist[i])cout << x << " ";
        cout << endl;
    }
    */
    for(int i = 0; i <= node; i++)
        adj[i].clear(), backadj[i].clear(), scclist[i].clear(), in[i] = 0, out[i] = 0;

    topo.clear();
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
