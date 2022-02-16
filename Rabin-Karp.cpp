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
ll S,T,hashTable[3][sz],p_pow[3][sz];
string s,s2;

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
    for(ll i=0 ; i<T ; i++){
        hashTable[0][i+1] = (hashTable[0][i] + ((s[i] - 'a' + 1) * p_pow[0][i])%MOD)%MOD;
        hashTable[1][i+1] = (hashTable[1][i] + ((s[i] - 'a' + 1) * p_pow[1][i])%mod)%mod;
    }
}

vector <ll> rabin_karp() {
        computeHash();
        long long h1_s = 0,h2_s = 0;
        for (int i = 0; i < S; i++) {
            h1_s = ((h1_s + (s2[i] - 'a' + 1) * p_pow[0][i]) % MOD)%MOD;
            h2_s = ((h2_s + (s2[i] - 'a' + 1) * p_pow[1][i]) % mod)%mod;
        }
        vector<ll> occurences;
        int cnt = 0;
        for (int i = 0; i + S - 1 < T; i++) {
            long long cur_h1 = (hashTable[0][i+S] + MOD - hashTable[0][i]) % MOD;
            long long cur_h2 = (hashTable[1][i+S] + mod - hashTable[1][i]) % mod;
            if ((cur_h1 == h1_s * p_pow[0][i] % MOD) && (cur_h2 == h2_s * p_pow[1][i] % mod))
                occurences.push_back(i),cnt++;
        }

    return occurences;
}

void solve() {
    cin >> s >> s2;
    S = s2.size(), T = s.size();
    vector <ll> v = rabin_karp();
    cout << v.size() << endl;
}

signed main() {
    int tst = 1;
    //int cs = 1;

    //cin >> tst;


    while(tst--){
        //cout << "Case " << cs++ << ": " ;
        solve();
    }

    return 0;
}




