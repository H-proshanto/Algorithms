#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n) {

    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }

        if(minIdx != i)
            swap(arr[i],arr[minIdx]);
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

    selectionSort(arr,n);
    printArray(arr,n);

    return 0;
}

