#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
using namespace std;

const int SIZE = 1000000 + 3;
int P[SIZE * 2];

string convertToNewString(string s) {
    string newString = "@";
    int n = s.size();
    for (int i = 0; i < n; i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string manachers(string s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;
    int n = Q.size();
    for (int i = 1; i < n - 1; i++) {
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }
        if (i + P[i] > r) {
            c = i;
            r = i + P[i];
        }
    }

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < n - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }
    //cout << maxPalindrome << endl;
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}


void solve() {
    string s;

    cin >> s;

    cout << manachers(s) << endl;
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




