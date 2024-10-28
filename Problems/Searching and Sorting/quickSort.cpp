#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr, int low, int high){
    bool upper=true;
    bool lower=true;
    bool loop=true;
    int start=low+1, end=high;
    int pivot=low;
    while(true){
        if(lower){
            if(arr[start]>arr[pivot] || start>high) lower=false;
            else start++;
        }
        if(upper){
            if(arr[end]<=arr[pivot]||upper<0) upper=false;
            else end--;
        }
        if(!(lower && upper)){
            if(start>end){
                int temp=arr[pivot];
                arr[pivot]=arr[end];
                arr[end]=temp;
                return end;
            }else{
                int temp=arr[start];
                arr[start]=arr[end];
                arr[end]=temp;
                lower=true;
                upper=true;
            }
        }
    }
}
void printArray(vector<int> arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
 
}
void quickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int main(){
    vector<int> arr = { 12, 11, 13, 5, 6 };
    quickSort(arr,0, arr.size()-1);
    printArray(arr, arr.size());
    return 0;
}