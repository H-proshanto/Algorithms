#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
#define sz 3009
using namespace std;

const ll p = 97;
const ll p2 = 113;
const ll p3 = 139;
const ll mod = 1000003133;
const ll MOD = 1000003889;
ll n,hashTable[3][sz],p_pow[3][sz];
string s;

void powEr() {
    p_pow[0][0] = 1;
    p_pow[1][0] = 1;
    for(int i=1 ; i<sz ; i++){
        p_pow[0][i] = (p_pow[0][i-1] * p)%MOD;
        p_pow[1][i] = (p_pow[1][i-1] * p2)%mod;
    }
}

void computeHash() {
    powEr();
    for(ll i=0 ; i<n ; i++){
        hashTable[0][i+1] = (hashTable[0][i] + ((s[i] - 'a' + 1) * p_pow[0][i])%MOD)%MOD;
        hashTable[1][i+1] = (hashTable[1][i] + ((s[i] - 'a' + 1) * p_pow[1][i])%mod)%mod;
    }
}


void solve() {
    cin >> s;
    computeHash();
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




