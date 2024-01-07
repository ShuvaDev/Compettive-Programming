#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

char matrix[1001][1001];
int visited[1001][1001];

void DFS(pair<int, int> src, int n, int m) {
    visited[src.first][src.second] = 1;

    vector<int> dir = {-1, 0, 1, 0, -1};

    for(int i = 0; i < 4; i++) {
        int nr = src.first + dir[i];
        int nc = src.second + dir[i + 1];

        if(nr < 0 || nc < 0 || nr >= n || nc >= m || matrix[nr][nc] == '#') continue;

        if(!visited[nr][nc]) 
            DFS({nr, nc}, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &matrix[i][j]);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == '.' && !visited[i][j]) {
                DFS({i, j}, n, m);
                count++;
            }
        }
    }

    cout << count;
    
    return 0;
}