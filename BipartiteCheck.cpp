#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
vector <int> adj[maxn];
int vis[maxn],col[maxn];

bool bipartite(int cur_node,bool clr) {
    vis[cur_node] = 1;
    col[cur_node] = clr;

    for(int node : adj[cur_node]) {
        if(!vis[node]) {
           if(bipartite(node,clr^1)==false)
                return false;
        }
        else{
            if(col[cur_node]==col[node])
                return false;
        }
    }

    return true;
}

void solve() {
    int node, edge;

    cin >> node >> edge;

    for(int i = 0; i < edge; i++) {
        int node1, node2 ;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        //adj[node2].push_back(node1);
    }

    int stNode;

    cin >> stNode;

    cout << bipartite(stNode,false) << endl;

    for(int i = 0; i <= node; i++)
        adj[i].clear(), vis[i] = 0,col[i] = 0;
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




