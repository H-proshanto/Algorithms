#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
#define iii pair <int,ii>
#define ff first
#define ss second
using namespace std;

const int maxn = 1e5 + 3;
vector <iii> adj;
int par[maxn];

int findParent(int n) {
    if(par[n] == n) return n;
    return findParent(par[n]);
}

int kruskal() {
    int minCost = 0;
    int sizee = adj.size();
    //ss = second , ff = first
    for(int i = 0; i < sizee; i++){
        int u = adj[i].ss.ff;
        int v = adj[i].ss.ss;
        int u_parent = findParent(u);
        int v_parent = findParent(v);

        if(v_parent != u_parent) {
            minCost+= adj[i].ff;
            par[v_parent] = par[u_parent];
        }
    }
    return minCost;
}


void solve() {
    int node, edge;

    cin >> node >> edge;

    for(int i = 0; i < edge; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        adj.push_back(iii(weight,ii(node1,node2)));
    }

    for(int i = 0; i <= node; i++)
        par[i] = i;

    sort(adj.begin(),adj.end());

    cout << kruskal() << endl;

    adj.clear();
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
