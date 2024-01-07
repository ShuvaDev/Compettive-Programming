#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> vc(n);
        for(int i = 0; i < n; i++) {
            cin >> vc[i];
        }
        sort(vc.begin(), vc.end());

        vc[0] += 1;
        int product = 1;
        for(int i = 0; i < n; i++) {
            
            
        }
        cout << product << endl;
    }
    
    
    
    return 0;
}