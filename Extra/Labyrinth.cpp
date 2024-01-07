#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

char arr[1005][1005];
vector<vector<bool>> visited(1005, vector<bool>(1005));
vector<vector<pair<int, int>>> parent(1005, vector<pair<int, int>>(1005));

void bfs(pair<int, int> src, int n, int m) {
    queue<pair<int, int>> Q;
    Q.push(src);
    visited[src.first][src.second] = 1;

    vector<int> dir = {-1, 0, 1, 0, -1};

    while(!Q.empty()) {
        auto u = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = u.first + dir[i];
            int nc = u.second + dir[i + 1];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == '#') continue;

            if(!visited[nr][nc]) {
                visited[nr][nc] = 1;
                Q.push({nr, nc});
                parent[nr][nc].first = u.first;
                parent[nr][nc].second = u.second;
            }
        }
    }
}

int main() {
    int n, m;
    vector<pair<int, int>> src(2);
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'A') {
                src[0].first = i;
                src[0].second = j;
            } else if(arr[i][j] == 'B') {
                src[1].first = i;
                src[1].second = j;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            parent[i][j].first = -1;
            parent[i][j].second = -1;
        }
    }


    bfs(src[0], n, m);
    

    string result = "";
    int flag = 1;
    auto s = src[1]; 

    while(1) {
        int sr = s.first;
        int sc = s.second;

        int nr = parent[s.first][s.second].first;
        int nc = parent[s.first][s.second].second;

        if(arr[nr][nc] == '#' || (nr == -1 && nc == -1)) {
            flag = 0;
            break;
        }

        if(nr == sr - 1 && nc == sc) {
            result += 'D';
        } else if(nr == sr + 1 && nc == sc) {
            result += 'U';
        } else if(sr == nr && sc == nc - 1) {
            result += 'L';
        } else {
            result += 'R';
        }

        if(arr[nr][nc] == 'A') {
            break;
        }
        s = parent[s.first][s.second];
    }

    if(flag) {
        cout << "YES\n";
        cout << result.size() << endl;
        for(int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
    } else {
        cout << "NO\n";
    }
    
    
    
    return 0;
}