#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
using namespace std;

const int maxn = 1e5 + 3;
vector <ii> adj[maxn];
int marked[maxn];

int prims(int x) {
    priority_queue<ii, vector<ii>, greater<ii> > Q;
    int y;
    int minimumCost = 0;
    ii p;
    Q.push(make_pair(0, x));

    while(!Q.empty()) {
        p = Q.top();
        Q.pop();
        x = p.second;
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;

        for(int i = 0; i < adj[x].size(); ++i) {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}


void solve() {
    int node, edge;

    cin >> node >> edge;

    for(int i = 0; i < edge; i++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        adj[node1].push_back({weight,node2});
        adj[node2].push_back({weight,node1});
    }

    int stNode;

    cin >> stNode;
    cout << prims(stNode) << endl;

    for(int i = 0; i <= node; i++)
        adj[i].clear(), marked[i] = 0;
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




