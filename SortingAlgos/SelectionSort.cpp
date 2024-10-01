#include<iostream>
#include<vector>
using namespace std;

void selectionSort(int* arr, int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[7] = {38,27,43,3,9,82,10};
    int n = 7;
    selectionSort(arr, n);
 
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}