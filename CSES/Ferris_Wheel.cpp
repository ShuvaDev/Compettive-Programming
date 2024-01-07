#include<bits/stdc++.h>
#define endl "\n"
#define sp " "

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> vec(n);

    for(int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());
    int count = 0;
    if(n == 1) count = 1;
    int L = 0, R = vec.size() - 1;
    while(L < R) {
        if(vec[L] + vec[R] > x) {
            R--;
            count++;
        }  else {
            L++;
            R--;
            count ++;
        }
        if(L == R) {
            count++;
        }
    }

    cout << count;
    
    
    
    return 0;
}