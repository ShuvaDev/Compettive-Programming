#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int e;
    cin >> e;

    vector<pair<int, int>> vc(e);

    for(int i = 0; i < e; i++) {
        cin >> vc[i].first;
        cin >> vc[i].second;
    }

    sort(vc.begin(), vc.end());

    for(auto &[f, s] : vc) {
        cout << f << " " << s << endl;
    }
    
    
    
    return 0;
}