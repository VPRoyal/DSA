// Code for Binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if(target>arr[high]|| target<arr[low]) return -1;
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if(mid==low || mid==high) return -1;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, low, mid - 1, target);
        return binarySearch(arr, mid + 1, high, target);
    }else return -1;
}
int main(){
   int V,N;
   cin >> V >> N;
   int arr[N];
   for(int i = 0; i < N; i++){
    cin >> arr[i];
   }
   sort(arr, arr + N);
   int res=binarySearch(arr, 0, N-1, V);
   if(res==-1) cout << "Not found" << endl;
   else cout << "Found at index " << res << endl;
   return 0;
}