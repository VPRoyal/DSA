#include <iostream>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long row, col;
        cin >> row >> col;
        long long edge=max(row,col);
        long long upper=edge*edge-(edge-1);
        if(edge%2==0){
            upper-=edge-row;
            upper+=edge-col;
        }else{
            upper+=edge-row;
            upper-=edge-col;
        }
        cout << upper << endl;
    }
    return 0;
}