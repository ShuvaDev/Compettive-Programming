#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        char str[8][8];
        int r, c, flag = 1;

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cin >> str[i][j];
                if(flag && str[i][j] != '.') {
                    r = i;
                    c = j;
                    flag = 0;
                }
            }
        }
        for(int i = r; i < 8; i++) {
            if(str[i][c] == '.') break;
            else cout << str[i][c];
        }
        cout << endl;
    }
    
    
    
    return 0;
}