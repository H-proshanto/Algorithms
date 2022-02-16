#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

const int maxn = 1e4;
int adj[maxn][maxn];


void solve() {
    int node, edge;

    cin >> node >> edge;

    for(int i = 0; i < node ; i++) {
        for(int j = 0; j < node; j++) {
            if(i!=j)adj[i][j] = INF;
            else adj[i][j] = 0;
        }
    }

    for(int i = 0; i < edge; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        adj[node1][node2] = weight;
        adj[node2][node1] = weight;
    }

    for (int k = 0; k < node; ++k) {
        for (int i = 0; i < node; ++i) {
            for (int j = 0; j < node; ++j) {
                //condition for negative cycle
                if (adj[i][k] < INF && adj[k][j] < INF)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
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





