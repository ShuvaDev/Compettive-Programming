#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        string str;
        cin >> str;

        int count = 0;
        for(int i = 0; i < n; ) {
            if(str[i] == 'B') {
                count++;
                i+=k;
            }
            else {
                i++;
            }

        }
        cout << count << endl;
    }
    
    
    
    return 0;
}