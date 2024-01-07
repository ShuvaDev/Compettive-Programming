#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        double result;
        cin >> a >> b >> c;

         result = abs(a - ((a + b) / (2 * 1.0))) / (c * 1.0);

         if(trunc(result) == result) {
            cout << trunc(result) << endl;
         } else {
            cout << trunc(result) + 1 << endl;
         }
    }
    
    
    
    return 0;
}