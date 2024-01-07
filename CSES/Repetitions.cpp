#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    string str;
    cin >> str;

    char start = str[0];
    int count = 1, MAX = 1;

    for(int i = 1; i < str.size(); i++) {
        if(str[i] == start) {
            count++;
        } else {
            MAX = max(count, MAX);
            start = str[i];
            count = 1;    
        }
    }
    MAX = max(MAX, count);
    cout << MAX;
    
    
    
    return 0;
}