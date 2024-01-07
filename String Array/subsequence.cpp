#include<bits/stdc++.h>
using namespace std;

bool isSubsequnce(string s1, string s2) {
    int i = 0, j = 0;

    while(i < s1.size() && j < s2.size()) {
        if(s1[i] == s2[j]) {
            j++;
        }
        i++;
    }

    return j == s2.size();
}

int main() {
    string s1 = "abcdefg", s2 = "bdh";

    if(isSubsequnce(s1, s2)) cout << "YES";
    else cout << "NO";
    
    
    
    return 0;
}