#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    
    map<int, int> mp;
    auto initalit = mp.begin();

    mp[2] = 10;
    mp[3] = 20;
    mp[5] = 40;
    mp[10] = 60;

    // initalit++;

    cout << (*initalit).first;
    
    
    return 0;
}