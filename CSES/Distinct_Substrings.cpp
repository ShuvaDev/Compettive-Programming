#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    string str;
    cin >> str;

    long long sum = 0;

    // For length 2
    // sum += str.size() - 1;

    // For length 3
    // sum += str.size() - 2;

    /*
        6
        abcdef
    */

   for(int i = 0; str.size() - i > 0; i++) {
        sum += str.size() - i;
   }    

   cout << sum;
    
    
    return 0;
}