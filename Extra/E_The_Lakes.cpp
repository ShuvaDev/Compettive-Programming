#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

vector<vector<int>> arr(1005, vector<int>(1005));

long long BFS(pair<int, int> src, int n, int m, vector<vector<bool>> &visited) {
    queue<pair<int, int>> Q;
    Q.push(src);
    visited[src.first][src.second] = 1;
    long long depth = 0;

    vector<int> dir = {-1, 0, 1, 0, -1};

    while(!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        depth += arr[u.first][u.second];

        for(int i = 0; i < 4; i++) {
            int nr = u.first + dir[i];
            int nc = u.second + dir[i + 1];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == 0) continue;

            if(!visited[nr][nc]) {
                visited[nr][nc] = 1;
                Q.push({nr, nc});
            }
        }
    } 

    return depth;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        vector<vector<bool>> visited(1005, vector<bool>(1005));
        int n, m;
        scanf("%d %d", &n, &m);


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        long long MAX = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && arr[i][j]) {
                    MAX = max(MAX, BFS({i, j}, n, m, visited));
                }
            }
        }

        cout << MAX << endl;
    }    
    
    
    
    return 0;
}