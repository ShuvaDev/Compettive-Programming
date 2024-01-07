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

        int ind = -1;
        for(int i = str.size() - 2; i >= 0; i--) {
            if(str[i] != '9') {
                if(str[i+1] >= '5') {
                    str[i] = str[i] + 1;
                    ind = i + 1;
                }
            }
        }
        if(str[0] >= '5') {
            cout << '1';
            ind = 0;
        }

        for(int i = 0; i < str.size(); i++) {
            if(ind == -1) {
                cout << str[i];
            } else {
                if(ind <= i) {
                    cout << '0';
                } else {
                    cout << str[i];
                }
            }
        }
        cout << endl;

    }
    
    
    
    return 0;
}