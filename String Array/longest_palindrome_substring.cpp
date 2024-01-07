#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    // n^2 solution

/*
    // For odd length
    string s1 = "acmadamaa";
    int max_len = 1;
    for(int center = 0; center < s1.size(); center++) {
        int len = 1;
        for(int i = 1; center - i >= 0 && center +i <   s1.size(); i++) {
            if(s1[center - i] == s1[center+i]) {
                len += 2;
            } else {
                break;
            }
        }
        if(len > max_len) max_len = len;
    }
    cout << max_len << endl;
*/   
    // For even length
    string str = "adaadb";

    int max_len = 1;
    for(int c1 = 0, c2 = c1 + 1; c2 < str.size(); c1++, c2++) {
        int len = 0;
        for(int i = 0; c1 - i >= 0 && c2 + i < str.size(); i++) {
            if(str[c1 - i] == str[c2 + i]) {
                len += 2;
            } else {
                break;
            }
        }
        if(len > max_len) max_len = len;
    }
    
    cout << max_len << endl;
    return 0;
}