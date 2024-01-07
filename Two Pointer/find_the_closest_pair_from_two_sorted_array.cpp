#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {5, 6, 7, 8, 10};

    int L = 0, R = vec2.size() - 1, diff = INT_MAX, x = 15, v1, v2;

    while(L < vec1.size() && R >= 0) {  
        int sum = vec1[L] + vec2[R];

        if(abs(sum - x) < diff) {
            diff = abs(sum - x);
            v1 = vec1[L];
            v2 = vec2[R];
        }

        if(sum > x) {
            R--;
        } else {
            L++;
        }
    }

    cout << v1 << sp << v2;
    
    
    
    return 0;
}