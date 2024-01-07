#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void findGates(vector<pair<int, int>> &gates, vector<vector<int>> &rooms) {
            for(int i = 0; i < rooms.size(); i++) {
                for(int j = 0; j < rooms[i].size(); j++) {
                    if(rooms[i][j] == 0) {
                        gates.push_back({i, j});
                    }
                }
            }
        }


        void BFS(vector<pair<int, int>> &gates, vector<vector<int>> &rooms) {
            queue<pair<int, int>> Q;
            vector<int> dir = {-1, 0, 1, 0, -1};

            for(auto gate : gates) {
                Q.push({gate.first, gate.second});

                while(!Q.empty()) {
                    auto u = Q.front();
                    Q.pop();

                    for(int i = 0; i < 4; i++) {
                        int nr = u.first + dir[i];
                        int nc = u.second + dir[i + 1];

                        if(nr < 0 || nc < 0 || nr >= rooms.size() || nc >= rooms[0].size() || rooms[nr][nc] == -1) {
                            continue;
                        } 
                        if(rooms[nr][nc] > rooms[u.first][u.second] + 1) {
                            Q.push({nr, nc});
                            rooms[nr][nc] = rooms[u.first][u.second] + 1;
                        }
                    }
                }
            }
        }

        void wallsAndGates(vector<vector<int>> &rooms) {
            vector<pair<int, int>> gates;
            findGates(gates, rooms);

            BFS(gates, rooms);
        }
};