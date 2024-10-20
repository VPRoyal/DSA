#include <iostream>
using namespace std;
void weirdAlgo(long long n){
    cout<<n<<" "<<endl;
    while(n!=1){
        if(n%2==0) n=(n/2);
        else n=(3*n+1);
        cout<<n<<" "<<endl;
    }
}
int main(){
    long long n;
    cin>>n;
    weirdAlgo(n);
    return 0;
}