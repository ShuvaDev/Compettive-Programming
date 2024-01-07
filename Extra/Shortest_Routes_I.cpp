#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 5000 + 5;

vector<int> adj_list[MAX_N];
vector<vector<int>> cost(MAX_N, vector<int>(MAX_N));
vector<bool> explored(MAX_N);
vector<long long> dist(MAX_N, LLONG_MAX / 2);
vector<int> first_best_parent(MAX_N, -1), sec_best_parent(MAX_N, -1);

void dijkstra(int src) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.push({0, src});
    dist[src] = 0;

    while(!PQ.empty()) {
        auto u = PQ.top();
        PQ.pop();

        auto u_cost = u.first;
        int u_node = u.second;

        if(!explored[u_node]) {
            explored[u_node] = 1;

            for(int i = 0; i < adj_list[u_node].size(); i++) {
                int v_node = adj_list[u_node][i];
                auto v_cost = cost[u_node][v_node];

                if(dist[v_node] > dist[u_node] + v_cost) {
                    dist[v_node] = dist[u_node] + v_cost;
                    
                    // second best parent determine
                    if(first_best_parent[v_node] == -1) {
                        sec_best_parent[v_node] = u_node;
                    } else {
                        sec_best_parent[v_node] = first_best_parent[v_node];
                    }
                    first_best_parent[v_node] = u_node;
                    

                    PQ.push({dist[u_node] + v_cost, v_node});
                }
            }
        }
    }
}

int main() {
    int node, edges;
    cin >> node >> edges;

    while(edges--) {
        int u, v, c;
        cin >> u >> v >> c;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
        cost[u][v] = c;
        cost[v][u] = c;
    }
    dijkstra(1);

    // Second best path print
    int curr_node = node;
    vector<int> result;


    while(curr_node != 1) {
        result.push_back(curr_node);
        curr_node = sec_best_parent[curr_node];
    } 
    
    long long sum = 0;
    
    result.push_back(1);
    for(int i = result.size() - 1; i > 0; i--) {
        cout << result[i] << " ";
    }
    // cout << sum << endl;
    return 0;
}