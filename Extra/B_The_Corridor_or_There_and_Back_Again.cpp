#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

bool isReturnPossible(vector<pair<int, int>> &trap, long long k) {
    for(int i = 0; i < trap.size(); i++) {
        if(trap[i].first >= k) {
            
        } else {
            if((k - trap[i].first) * 2 >= trap[i].second) {
                return false;
            }
        }
    }
    return true;
}

int find_k(vector<pair<int, int>> &trap) {
    long long int L = 0, R = INT_MAX / 2;

    while(L < R) {
        long long k = L + (R - L + 1) / 2;

        if(isReturnPossible(trap, k)) {
            L = k;
        } else {
            R = k - 1;
        }
    }
    return R;
}

int main() {
    int t;
    cin >>  t;
    
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> trap;

        for(int i = 1; i <= n; i++) {
            int d, s;
            scanf("%d %d", &d, &s);
            trap.push_back({d, s});
        }

        sort(trap.begin(), trap.end());

        // cout << isReturnPossible(trap, 1);

        cout << find_k(trap) << endl;

    } 
    
    
    
    return 0;
}