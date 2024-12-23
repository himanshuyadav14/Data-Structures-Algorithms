#include<iostream>
#include<vector>
using namespace std;

// T.C = Worst case O(n^2); 
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];    // Take the current element
        int j = i - 1;

        // Move elements that are greater than the key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;    // Insert the key at the correct position
    }
}

int main(){
    int arr[7] = {38,27,43,3,9,82,10};
    int n = 7;
    insertionSort(arr, n);
 
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}