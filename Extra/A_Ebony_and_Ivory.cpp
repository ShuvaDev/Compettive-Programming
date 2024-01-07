#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = 0, flag = 0;
    for(int i = 1; ;i++) {
        int y = c - x;
        if(y < 0) {
            break;
        }

        if(y % b == 0) {
            flag = 1;
            break;
        }


        x += a;
    }
    if(flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    
    return 0;
}