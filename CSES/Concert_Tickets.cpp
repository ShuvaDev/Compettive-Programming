#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int n, m, price;
    cin >> n >> m;

    multiset<int> ticket_price;

    for(int i = 0; i < n; i++) {
        cin >> price;
        ticket_price.insert(price);
    }

    vector<int> a;
    for(int i = 0; i < m; i++) {
        cin >> price;
        a.push_back(price);
    }
    for(int i = 0; i < m; i++) {
        if(ticket_price.size() == 0 || *ticket_price.begin() > a[i]) {
            cout << -1 << endl;
        } else {
            auto it = ticket_price.upper_bound(a[i]);
            it--;
            cout << *it << endl;
            ticket_price.erase(it);
        }
    }

    
    
    
    return 0;
}