#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;
    char a=NULL;
    int count=0;
    long long length = str.length();
    int maxSeq=0;
    for (long long i = 0; i < length; i++)
    {
        if(a!=str[i]) count=0;
        a=str[i];
        count++;
        maxSeq=max(maxSeq,count);

    }
    cout<<maxSeq<<endl;
    return 0;
    
}