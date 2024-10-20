#include <iostream>
#include <string>
using namespace std;

int main(){
    long long i;
    cin >> i;
    string even, odd;
    if(i==3||i==2){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    long long a=1;
    while(a<=i){
        if(a%2 == 0) even += to_string(a)+" ";
        else odd += to_string(a)+" ";
        a++;
    }
    cout<<(even+odd)<<endl;
    return 0;
}