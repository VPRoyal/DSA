// In this Search we iterate over the array of elements and check if certain element is present or not.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,V;
    cin >> n>>V;

    // Use vector instead of array
    vector<int> arr(n);

    // Input elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the vector
    sort(arr.begin(), arr.end());

    // Search for the element
    for (int i=0; i < arr.size(); i++)
    {
        if(V==arr[i]){
            cout << i << endl;
            return 0;
        }
    }
    
    cout << endl;

    return 0;
}
