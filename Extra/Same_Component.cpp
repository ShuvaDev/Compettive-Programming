#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

char arr[1000][1000];
int dist[1000][1000];
bool visited[1000][1000];

void bfs(pair<int, int> src, pair<int, int> dst, int n, int m) {
    dist[src.first][src.second] = 0;

    queue<pair<int, int>> Q;
    Q.push(src);

    while(!Q.empty()) {
        auto front = Q.front();
        visited[front.first][front.second] = 1;
        Q.pop();

        vector<int> dir = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int nr = front.first + dir[i], nc = front.second + dir[i + 1];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc] || arr[nr][nc] == '-') {
                continue;
            }

        }
    }
}

int main() {
    int n, m;
    cin >>  n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    pair<int, int> src, dst;
    cin >> src.first >> src.second;
    cin >> dst.first >> dst.second;

    bfs(src, dst);
    
    
    return 0;
}