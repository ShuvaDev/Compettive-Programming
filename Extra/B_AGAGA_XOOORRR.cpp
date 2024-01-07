#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        long long result = 0;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            result ^= arr[i];
        }

        if(result == 0) {
            cout << "YES\n";
        } else {
            int count = 0;
            long long r = 0;
            for(int i = 0; i < n; i++) {
                r ^= arr[i];
                if(r == result) {
                    count++;
                    r = 0;
                }
            }
            if(count >= 2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }


    }
    
    
    
    return 0;
}