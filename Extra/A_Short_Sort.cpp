#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string str;
        cin >> str;

        if(str == "abc" || str == "bac" || str == "acb" || str == "cba") {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    
    
    return 0;
}