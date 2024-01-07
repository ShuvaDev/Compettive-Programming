#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 5000 + 5;

vector<int> adj_list[MAX_N], cost[MAX_N];
vector<int> dist(MAX_N, INT_MAX / 2);
vector<bool> explored(MAX_N);

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, src});
    dist[src] = 0;

    while(!PQ.empty()) {
        auto u = PQ.top();
        PQ.pop();
        
        int u_cost = u.first;
        int u_node = u.second;

        if(!explored[u_node]) {
            explored[u_node] = 1;

            for(int i = 0; i < adj_list[u_node].size(); i++) {
                int v_node = adj_list[u_node][i];
                int v_cost = cost[u_node][i];

                if(dist[v_node] > dist[u_node] + v_cost) {
                    dist[v_node] = dist[u_node] + v_cost;
                    PQ.push({dist[u_node] + v_cost, v_node});
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, r;
        scanf("%d %d", &n, &r);

        while(r--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
        }
    }
    
    
    
    return 0;
}