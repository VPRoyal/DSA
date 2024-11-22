#include <iostream>
#include <string>

using namespace std;
// There is logic in the hackerrank problem that if a string A is bigger than the string B 
// and all characters of B are matching in A than character of A will be taken in priority.
bool compare(const string &a, int i, const string &b, int j) {
    while (i < static_cast<int>(a.length()) && j < static_cast<int>(b.length())) {
        if (a[i] < b[j]) return true;
        else if (a[i] > b[j]) return false;
        i++;
        j++;
    }
    return i == static_cast<int>(a.length()) ? false : true;
}

string morganAndString(const string &a, const string &b) {
    int lenA = a.length(), lenB = b.length();
    string result;
    int pA = 0, pB = 0;

    while (pA < lenA && pB < lenB) {
        if (a[pA] < b[pB]) {
            result += a[pA++];
        } else if (a[pA] > b[pB]) {
            result += b[pB++];
        } else {
            if (compare(a, pA + 1, b, pB + 1)) {
                result += a[pA++];
                while (pA < lenA && a[pA] == a[pA - 1]) {
                    result += a[pA++];
                }
            } else {
                result += b[pB++];
                while (pB < lenB && b[pB] == b[pB - 1]) {
                    result += b[pB++];
                }
            }
        }
    }

    if (pA < lenA) {
        result += a.substr(pA);
    }

    if (pB < lenB) {
        result += b.substr(pB);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        string a, b;
        cin >> a >> b;
        string result = morganAndString(a, b);
        cout << result << endl;
    }
    return 0;
}
