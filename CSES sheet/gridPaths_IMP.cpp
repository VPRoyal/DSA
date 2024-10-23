#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool visited[7][7];
string path;
int answer = 0;

inline bool valid(int i, int j) {

    if (i < 7 && j < 7 && i >= 0 && j >= 0 && ! visited[i][j]) {
        return true;
    }


    return false;
}

void dfs(int i, int j, int a) {
    //dbg(i, j, a);

    if (i == 6 && j == 0) {
        if (a == 48) {
            answer++;
        }
        return;
    }

    visited[i][j] = true;

    // go up
    if ((path[a] == 'U' || path[a] == '?')) {
        if (i > 0 && valid(i - 1, j)) {
            if (!(!valid(i - 2, j) && valid(i - 1, j - 1) && valid(i - 1, j + 1)) || (i - 1 == 6 && j == 0)) {
                dfs(i - 1, j, a + 1);
            }
        }
    }

    if (path[a] == 'D' || path[a] == '?') {
        if (i < 6 && valid(i + 1, j)) {
            if (!(!valid(i + 2, j) && valid(i + 1, j - 1) && valid(i + 1, j + 1))) {
                dfs(i + 1, j, a + 1);
            }
        }
    }

    if (path[a] == 'L' || path[a] == '?') {
        if (j > 0 && valid(i, j - 1)) {
            if (!(!valid(i, j - 2) && valid(i - 1, j - 1) && valid(i + 1, j - 1))) {
                dfs(i, j - 1, a + 1);
            }
        }
    }

    if (path[a] == 'R' || path[a] == '?') {
        if (j < 6 && valid(i, j + 1)) {
            if (!(!valid(i, j + 2)  && valid(i - 1, j + 1) && valid(i + 1, j + 1))) {
                dfs(i, j + 1, a + 1);
            }
        }
    }

    visited[i][j] = false;

    return;
}

int main(){
    cin >> path;
    dfs(0, 0, 0);
    cout << answer;
    return 0;
}