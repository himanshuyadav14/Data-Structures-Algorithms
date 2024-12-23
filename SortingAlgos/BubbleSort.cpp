#include<iostream>
#include<vector>
using namespace std;

// T.C = O(n^2)
void bubbleSort(int* arr, int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            } 
        }
        if(!swapped) break;
    }
}

int main(){
    int arr[7] = {38,27,43,3,9,82,10};
    int n = 7;
    bubbleSort(arr, n);
 
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}