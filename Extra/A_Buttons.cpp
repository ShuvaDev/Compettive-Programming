#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == b) {
            if(c % 2) {
                cout << "First\n";
            } else {
                cout << "Second\n";
            }
        } else {
            if(a > b) {
                cout << "First\n";
            } else {
                cout << "Second\n";
            }
        }
    }
    
    
    
    return 0;
}