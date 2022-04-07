#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n) {
    int mx = INT_MIN, mn = INT_MAX;

    for(int i = 0; i < n; i++) {
        mx = max(mx,arr[i]);
        mn = min(mn,arr[i]);
    }

    int sz = mx - mn  + 1;
    vector <int> cnt(sz),v(n);

    for(int i = 0; i < n; i++)
        cnt[arr[i] - mn]++;
    for(int i = 1; i < sz; i++)
        cnt[i] += cnt[i-1];
    for(int i = n - 1; i >= 0 ;i--) {
        v[cnt[arr[i] - mn] - 1] = arr[i];
        cnt[arr[i] - mn]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = v[i];
    }
}

void printArray(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4,5,2,1,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr,n);
    printArray(arr,n);

    return 0;
}



