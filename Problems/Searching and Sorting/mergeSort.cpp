#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
 
}

// Conquer - sorting and merging back the divided arrays
void merge(int arr[], int start, int mid, int end){
    int mergeArray[end-start+1];
    int idx1=start;
    int idx2=mid+1;
    int idx=0;
    while(idx1<=mid&&idx2<=end){
            if(arr[idx1]>arr[idx2]) mergeArray[idx++]=arr[idx2++];
            else mergeArray[idx++]=arr[idx1++];
    }
    while(idx1<=mid) mergeArray[idx++]=arr[idx1++];
    while(idx2<=end) mergeArray[idx++]=arr[idx2++];
    
    for(idx=start; idx<=end; idx++) arr[idx]=mergeArray[idx-start];
}

// Divide - Dividing the array into small sorted array
void mergeSort(int arr[], int start, int end){
    if(start>=end) return;
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}
int main(){
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,N-1);
    printArray(arr, N);
    return 0;
}