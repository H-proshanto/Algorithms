#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n) {

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

    }
}

void printArray(int arr[],int n) {

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4,5,2,1,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr,n);
    printArray(arr,n);

    return 0;
}

