#include <bits/stdc++.h>
// Calculate total shifts in insertion sort.
// For this we need to know the total number of elements which are greater than and in the left of an array item, for all such array items,
// which is equal to the total number of shifts required in insertion sort.
// To calculate this we can utilize merge sort and add all counts of occurence of left elements which are greater than the left elements,
// this will give shifts count in NlongN time whereas insertion sort takes N^2 time.
using namespace std;
long long merge(int arr[], int start, int mid, int end){
    int mergeArray[end-start+1];
    int idx1=start;
    int idx2=mid+1;
    int idx=0;
    long long shift=0;
    while(idx1<=mid&&idx2<=end){
            if(arr[idx1]>arr[idx2]) {
                mergeArray[idx++]=arr[idx2++];
                shift+=(mid-idx1+1);
            }
            else mergeArray[idx++]=arr[idx1++];
    }
    while(idx1<=mid) mergeArray[idx++]=arr[idx1++];
    while(idx2<=end) mergeArray[idx++]=arr[idx2++];
    
    for(idx=start; idx<=end; idx++) arr[idx]=mergeArray[idx-start];
    return shift;
}
long long  mergeSort(int arr[],int start, int end){
    long long shifts=0;
    if(start>=end) return shifts;
    int mid = start + (end-start)/2;
    shifts+=mergeSort(arr, start, mid);
    shifts+=mergeSort(arr, mid+1, end);
    shifts+=merge(arr, start, mid, end);
    return shifts;
}
int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << mergeSort(arr, 0,n-1) << endl;
    }
    return 0;

}