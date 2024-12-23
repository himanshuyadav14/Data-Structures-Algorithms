#include<iostream>
#include<vector>
using namespace std;

//space complexity : O(n)
//Time complexity : O(nlogn)
void mergeTwoSortedArrays(int *arr, int s, int e){ //O(n)
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *left = new int[len1];
    int *right = new int[len2];

    for(int i=0; i<len1; i++){
        left[i] = arr[s+i];
    }

    for(int i=0; i<len2; i++){
        right[i] = arr[mid + 1 + i];
    }

    int index1 = 0;
    int index2 = 0;
    int k = s;

    while(index1 < len1 && index2 < len2){
        if(left[index1] < right[index2]){
            arr[k++] = left[index1++];
        }else{
            arr[k++] = right[index2++];
        }
    }

    while(index1 < len1){
        arr[k++] = left[index1++];
    }

    while(index2 < len2){
        arr[k++] = right[index2++];
    }
}

void mergeSort(int *arr, int s, int e){ //logn
    //Base case
    if(s>=e) return;

    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    mergeTwoSortedArrays(arr,s,e);
}
int main(){
    int arr[7] = {38,27,43,3,9,82,10};
    int n = 7;
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}