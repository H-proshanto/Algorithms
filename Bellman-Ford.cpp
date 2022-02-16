#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
using namespace std;

const int INF = 1000000000;
const int maxn = 1e5+3;
vector <ii> adj[maxn];
int n,m;

bool bellman_ford(int s) {
    // 0 based
    vector<int> dis(n,INF);
    vector<int> cnt(n,0);
    vector<bool> vis(n,false);
    queue<int> q;

    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        vis[v] = false;

        for (auto child : adj[v]) {
            int to = child.first;
            int len = child.second;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
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

    ll stNode;
    n = node, m = edge;

    cin >> stNode;
    cout << bellman_ford(stNode) << endl;

    for(int i = 0; i <= node; i++)
        adj[i].clear();
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




