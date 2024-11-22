// This alsgorithm is used to sort the given array of elements in a given range by counting its occurences


#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(const vector<int>& arr, int range){
    // Create a frequency array and a max value integer to get the frequency.
    vector<int> freq(range+1, 0);
    vector<int> res;
    int maxVal=INT_MIN;
    for(int val:arr){
        freq[val]++;
        // Max Value for optimiziation, so that if highest number is less than the range then we stop it eralier;
        maxVal=max(maxVal, val);  
    }
    for(int i=0;i<=maxVal;i++){
        if(freq[i]>0){
            for(int j=0;j<freq[i];j++){
                res.push_back(i);
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr={5,3,6,8,9,5,20,30};
    int range=30;
    arr=countSort(arr, range);
}