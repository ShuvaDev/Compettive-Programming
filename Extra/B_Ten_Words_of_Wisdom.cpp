#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, max = 0, res = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;

            if(a <= 10) {
                if(b > max) {
                    max = b;
                    res = i;
                }
            }
        }
        cout << res << endl;

    }
    
    
    
    return 0;
}