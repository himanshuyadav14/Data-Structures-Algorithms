#include<iostream>
#include<vector>
using namespace std;
 
// Best and average : O(nlogn)
// Worst : O(n^2)

int partition(int* arr, int s, int e){
    int pivot = arr[s];
 
    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot) cnt++;
    }
 
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
 
    //left and right vaala part 
    int i = s;
    int j = e;
 
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if(i < pivotIndex && j > pivotIndex) swap(arr[i++],arr[j--]);
    }
 
    return pivotIndex;
}
 
void quickSort(int* arr, int s, int e){
    //Base case
    if(s>=e) return;

    int p = partition(arr, s, e);
 
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[7] = {38,27,43,3,9,82,10};
    int n = 7;
    quickSort(arr, 0, n-1);
 
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}