#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int arr[105][105];

int main() {
    int n;
    cin >> n;

    while(n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int i = a; i < b; i++) {
            for(int j = c; j < d; j++) {
                arr[i][j] = 1;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            count += arr[i][j];
        }
    }

    cout << count;
    
    
    
    return 0;
}