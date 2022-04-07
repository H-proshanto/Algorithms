#include <bits/stdc++.h>
using namespace std;

int partitionArray(int arr[], int st, int en) {
    int pivot = arr[en];
    int i = st - 1;

    for(int j = st; j <= en - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[en]);
    return i + 1;

}

void quickSort(int arr[], int st, int en) {

    if(st < en) {
        int par = partitionArray(arr,st,en);

        quickSort(arr,st,par - 1);
        quickSort(arr,par + 1,en);
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

    quickSort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}



