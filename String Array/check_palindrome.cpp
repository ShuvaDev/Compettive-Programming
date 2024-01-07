#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int len = s.size();
    if(len <= 1) return true;
    
    if(s[0] == s[len-1]) {
        string ss;
        for(int i = 1; i < len-1; i++) {
            ss += s[i];
        }
        return isPalindrome(ss);
    } else {
        return false;
    }
}

int main() {
    string str = "mamm";
    
    if(isPalindrome(str)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}