#include<bits/stdc++.h>
using namespace std;

int isSubstring(string s1, string s2) {
    for(int i = 0; i < s1.size(); i++) {
        int flag = 1;
        for(int j = 0; j < s2.size(); j++) {
            if(i + j >= s1.size()) {
                return 0;
            }
            if(s1[i+j] != s2[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) return 1;
    }
    return 0;
}

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    if(isSubstring(s1, s2)) cout << "YES\n";
    else cout << "NO\n";
    
    
    
    return 0;
}