#include <bits/stdc++.h>
using namespace std;

void mergeArray(int arr[], int st, int mid, int en) {
    int n = mid - st + 1;
    int m = en - mid;

    int A[n],B[m];

    for(int i = 0; i < n; i++)
        A[i] = arr[i + st];
    for(int i = 0; i < m; i++)
        B[i] = arr[i + mid + 1];

    int i = 0, j = 0, k = st;
    while(i < n && j < m) {
        if(A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        }
        else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }

    while(i < n) {
        arr[k++] = A[i++];
    }

    while(j < m) {
        arr[k++] = B[j++];
    }
}


void mergeSort(int arr[], int st, int en) {
    if(st >= en)
        return ;

    int mid = st + (en - st) / 2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,en);
    mergeArray(arr,st,mid,en);
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

    mergeSort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}


