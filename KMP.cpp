#include <bits/stdc++.h>
#define ll long long
#define ii pair <int,int>
using namespace std;

const int maxn = 1e7;
int failure[maxn];

void build_failure_function(string pattern, int m) {
  failure[0] = 0;
  failure[1] = 0;

  for(int i = 2; i <= m; i++) {
    int j = failure[i - 1];
    while(true) {
      if(pattern[j] == pattern[i - 1]) {
        failure[i] = j + 1;
        break;
      }
      if(j == 0) {
          failure[i] = 0;
          break;
      }
      j = failure[j];
    }
  }
}

bool kmp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    build_failure_function(pattern, m);
    int i = 0,j = 0;
    while(true) {
        if(j == n) {
            return false;
        }
        if(text[j] == pattern[i]) {
            i++;
            j++;
            if(i == m) {
                return true;
            }
        }
        else {
            if (i == 0) {
                j++;
            }
            else {
                i = failure[i];
            }
        }
  }
  return false;
}


void solve() {
    string s, s2;

    cin >> s >> s2;
    cout << kmp(s,s2) << endl;
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




