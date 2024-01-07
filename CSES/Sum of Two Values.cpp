#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> vec(n + 1);

    map<int, vector<int>> mp;

    for(int  i = 1; i <= n; i++) {
        cin >> vec[i];
        mp[vec[i]].push_back(i);
    }


    sort(vec.begin(), vec.end());

    int L = 1, R = n, flag = 0;

    while(L < R) {
        if(vec[L] + vec[R] == x) {
            if(vec[L] == vec[R]) {
                cout << min(mp[vec[L]][0], mp[vec[L]][1])  << sp << max(mp[vec[L]][0], mp[vec[L]][1]);
            } else {
                cout << min(mp[vec[L]][0], mp[vec[R]][0])  << sp << max(mp[vec[L]][0], mp[vec[R]][0]);
            }


            flag = 1;
            break;
        } else if(vec[L] + vec[R] > x) {
            R--;
        } else {
            L++;
        }
    }

    if(flag == 0) cout << "IMPOSSIBLE";
    
    
    
    return 0;
}