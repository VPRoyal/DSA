#include <iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long arr[n]={};
    for(long long i=0; i<n; i++){
        cin >> arr[i];
    }
    long long count=0;
    for(long long i=1; i<n; i++){
        long long upperBound=arr[i]-arr[i-1];
        if(upperBound<0){
            upperBound*=-1;
            count+=upperBound;
            arr[i]+=upperBound;
        }
    }
    cout <<'\n' << count << endl;
    return 0;
    
}