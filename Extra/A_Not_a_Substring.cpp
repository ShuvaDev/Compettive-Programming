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

        if(str == "()")  cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < str.size(); i++) {
                if((i + 1) < str.size() && str[i] == ')' && str[i + 1] == '(') {
                    cout << "(())";
                    i++;
                } else if(str[i] == '(') {
                    cout << "()";
                } else if(str[i] == ')') {
                    cout << "()";
                }
            }
            cout << endl;
        }
        

    }
    
    
    
    return 0;
}